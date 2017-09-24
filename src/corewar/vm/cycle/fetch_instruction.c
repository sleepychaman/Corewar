/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2017/09/22 14:19:57 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static int		is_compatible(int type, int possibilities)
{
	if (type == REG_CODE)
	{
		if (possibilities & T_REG)
			return (T_REG);
	}
	else if (type == DIR_CODE)
	{
		if (possibilities & T_DIR)
			return (T_DIR);
	}
	else if (type == IND_CODE)
	{
		if (possibilities & T_IND)
			return (T_IND);
	}
	return (UNSET);
}

static t_bool	check_params_type(char encoding, t_process *process, t_op *op)
{
	int	count;
	int	ret;

	count = -1;
	process->instruction.type[0] = (encoding & (IND_CODE << 6)) >> 6;
	process->instruction.type[1] = (encoding & (IND_CODE << 4)) >> 4;
	process->instruction.type[2] = (encoding & (IND_CODE << 2)) >> 2;
	process->instruction.pc_gap++;
	while ((++count) < op->arg_nbr)
	{
		ret = is_compatible(process->instruction.type[count],
							op->arg_type[count]);
		if (ret == UNSET)
		{
			reset_instruction(process, FALSE);
			return (FALSE);
		}
		if (ret == T_DIR && !op->has_idx)
			ret *= 2;
		else if (ret == T_IND)
			ret = 2;
		process->instruction.size[count] = ret;
		process->instruction.pc_gap += ret;
	}
	return (TRUE);
}

static void		get_single_param(t_process *process, t_op *op_detail)
{
	int	ret;

	if (op_detail->arg_type[0] == T_REG)
		process->instruction.type[0] = REG_CODE;
	else if (op_detail->arg_type[0] == T_DIR)
		process->instruction.type[0] = DIR_CODE;
	else if (op_detail->arg_type[0] == T_IND)
		process->instruction.type[0] = IND_CODE;
	if (op_detail->arg_type[0] == T_DIR && !op_detail->has_idx)
		ret = op_detail->arg_type[0] * 2;
	else
		ret = op_detail->arg_type[0];
	process->instruction.size[0] = ret;
	process->instruction.pc_gap += ret;
}

static void		fetch_memory(t_process *process, t_byte *memory, int encoding)
{
	int		count;
	int		count2;
	int		prog_count;
	char	*cast;

	count = 0;
	prog_count = process->prog_count + 1 + encoding;
	while (process->instruction.type[count] != UNSET && count < 3)
	{
		process->instruction.value[count] = 0;
		cast = (char *)&process->instruction.value[count];
		count2 = -1;
		while (++count2 < process->instruction.size[count])
		{
			cast[(process->instruction.size[count] - 1) - count2] =
					get_memory(memory, prog_count + count2)->content;
		}
		if (process->instruction.size[count] == T_DIR)
			process->instruction.value[count] =
				(short)process->instruction.value[count];
		else if (process->instruction.size[count] == T_DIR * 2)
			process->instruction.value[count] =
				ft_revint32(process->instruction.value[count]);
		prog_count += process->instruction.size[count++];
	}
}

void			fetch_instruction(t_process *process, t_byte *memory)
{
	t_op	*op_detail;
	int		op_code;

	op_code = (int)memory[process->prog_count].content;
	if (op_code >= 1 && op_code <= NBR_OP)
	{
		op_detail = get_op_detail(op_code);
		process->instruction.op_code = op_code;
		process->instruction.name = op_detail->mnemonic;
		process->instruction.pc_gap = 1;
		if (op_detail->encoding && !check_params_type(
			get_memory(memory, process->prog_count + 1)->content,
			process, op_detail))
			return ;
		else if (!op_detail->encoding)
			get_single_param(process, op_detail);
		fetch_memory(process, memory, op_detail->encoding);
		process->cycle_rest = op_detail->cycle;
	}
}
