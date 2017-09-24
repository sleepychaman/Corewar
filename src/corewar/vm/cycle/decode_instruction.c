/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:43:57 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	decode_instruction(t_process *process, t_byte *memory)
{
	int	count;

	count = 0;
	while (count < MAX_PARAMS && process->instruction.type[count] != UNSET)
	{
		if (process->instruction.type[count] == REG_CODE)
		{
			if (process->instruction.value[count] < 1
				|| process->instruction.value[count] > REG_NUMBER)
			{
				reset_instruction(process, FALSE);
				return ;
			}
		}
		count++;
	}
	if (process->instruction.op_code == 1)
		memory[process->prog_count].is_live = TRUE;
}
