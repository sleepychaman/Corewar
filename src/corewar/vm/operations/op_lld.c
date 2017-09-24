/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2017/09/22 14:20:54 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_lld(t_process *process, t_param *params, t_vm_data *data)
{
	int	first;

	first = 0;
	if (process->instruction.type[0] == DIR_CODE)
		first = process->instruction.value[0];
	else if (process->instruction.type[0] == IND_CODE)
		first = get_int_memory(data->memory,
			get_adress(process->prog_count + process->instruction.value[0]));
	*(int *)&process->reg[process->instruction.value[1] - 1] = first;
	(void)params;
}
