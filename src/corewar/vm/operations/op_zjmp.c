/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2017/09/22 14:20:58 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_zjmp(t_process *process, t_param *params, t_vm_data *data)
{
	if (process->carry)
	{
		process->instruction.pc_gap = 0;
		process->prog_count =
				get_adress(process->prog_count + process->instruction.value[0]);
	}
	(void)params;
	(void)data;
}
