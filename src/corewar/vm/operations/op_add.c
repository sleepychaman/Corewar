/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:44:06 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_add(t_process *process, t_param *params, t_vm_data *data)
{
	int	first;
	int	second;

	first = *(int *)&process->reg[process->instruction.value[0] - 1];
	second = *(int *)&process->reg[process->instruction.value[1] - 1];
	*(int *)&process->reg[process->instruction.value[2] - 1] = first + second;
	(void)params;
	(void)data;
}
