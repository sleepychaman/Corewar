/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2017/09/22 14:20:59 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_sti(t_process *process, t_param *params, t_vm_data *data)
{
	int	first;
	int	second;
	int	count;

	first = 0;
	second = 0;
	count = -1;
	if (process->instruction.type[1] == REG_CODE)
		first = *(int *)&process->reg[process->instruction.value[1] - 1];
	else if (process->instruction.type[1] == DIR_CODE)
		first = process->instruction.value[1];
	else if (process->instruction.type[1] == IND_CODE)
		first = get_int_memory(data->memory,
			calc_indirect(process->prog_count, process->instruction.value[1]));
	if (process->instruction.type[2] == REG_CODE)
		second = *(int *)&process->reg[process->instruction.value[2] - 1];
	else if (process->instruction.type[2] == DIR_CODE)
		second = process->instruction.value[2];
	while (++count < MAX_PLAYERS)
		if (*(int *)&process->reg[0] == params->champs[count].number)
			break ;
	put_int_memory(data->memory,
	calc_indirect(process->prog_count, (first + second)),
	*(int *)&process->reg[process->instruction.value[0] - 1], count + 1);
	(void)params;
}
