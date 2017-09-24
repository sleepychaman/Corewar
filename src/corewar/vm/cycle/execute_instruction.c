/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2016/04/20 17:23:23 by ryabicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	execute_instruction(t_process *proc, t_param *params, t_vm_data *data)
{
	static void	(*operations[NBR_OP])() = {
		op_live, op_ld, op_st, op_add, op_sub, op_and, op_or, op_xor,
		op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff
	};

	(*operations[proc->instruction.op_code - 1])(proc, params, data);
	if (!params->graphic && params->verb_lvl >= VERB_LVL_OPERATIONS)
		print_operation(proc);
}
