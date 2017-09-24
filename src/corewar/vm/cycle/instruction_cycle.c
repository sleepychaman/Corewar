/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_cycle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:25:26 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdlib.h>

t_op	g_op_tab[NBR_OP] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
};

void		reset_instruction(t_process *process, t_bool carry)
{
	int	count;
	int	op;

	count = 0;
	op = process->instruction.op_code;
	if (op == 2 || (op >= 4 && op <= 8) || op == 13 || op == 14)
		process->carry = carry;
	process->instruction.op_code = UNSET;
	process->instruction.name = NULL;
	process->instruction.pc_gap = UNSET;
	while (count < MAX_PARAMS)
	{
		process->instruction.type[count] = UNSET;
		process->instruction.size[count] = UNSET;
		process->instruction.value[count] = UNSET;
		count++;
	}
}

t_op		*get_op_detail(int op_code)
{
	int	count;

	count = 0;
	while (count < NBR_OP)
	{
		if (g_op_tab[count].op_code == op_code)
			return (&g_op_tab[count]);
		count++;
	}
	return (NULL);
}

void		move_prog_count(t_process *process, t_byte *memory, t_param *params)
{
	int	prog_count;
	int	count;

	count = 0;
	while (*(int *)&process->reg[0] != params->champs[count].number)
		count++;
	if (memory[process->prog_count].color == count + 1)
		memory[process->prog_count].is_pc = FALSE;
	if (process->instruction.pc_gap != UNSET)
		prog_count = process->prog_count + process->instruction.pc_gap;
	else
		prog_count = process->prog_count + 1;
	process->prog_count = get_adress(prog_count);
	memory[process->prog_count].color = count + 1;
	memory[process->prog_count].is_pc = TRUE;
}

void		instruction_cycle(t_param *params, t_vm_data *data)
{
	t_plist		*iter;
	t_process	*process;

	iter = data->head->next;
	while (iter)
	{
		process = &iter->process;
		if (process->cycle_rest)
			process->cycle_rest--;
		if (!process->cycle_rest)
		{
			if (process->instruction.op_code != UNSET)
			{
				execute_instruction(&iter->process, params, data);
				move_prog_count(process, data->memory, params);
				reset_instruction(process, TRUE);
			}
			fetch_instruction(process, data->memory);
			decode_instruction(process, data->memory);
		}
		if (process->instruction.op_code == UNSET)
			move_prog_count(process, data->memory, params);
		iter = iter->next;
	}
}
