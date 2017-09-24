/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 13:41:58 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:44 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static void	add_label_to_arg(t_parse *p)
{
	int		diff;
	int		arg_index;

	diff = LABEL_INDEX - CALL_LABEL_OPINDEX;
	arg_index = (int)CALL_LABEL_ARGINDEX;
	if (arg_index > 0)
	{
		CHAMPION->bytecode[arg_index + 0] = diff >> 24 & 0xff;
		CHAMPION->bytecode[arg_index + 1] = diff >> 16 & 0xff;
		CHAMPION->bytecode[arg_index + 2] = diff >> 8 & 0xff;
		CHAMPION->bytecode[arg_index + 3] = diff >> 0 & 0xff;
	}
	else if (arg_index < 0)
	{
		arg_index *= -1;
		CHAMPION->bytecode[arg_index + 0] = diff >> 8 & 0xff;
		CHAMPION->bytecode[arg_index + 1] = diff >> 0 & 0xff;
	}
}

int			add_label(t_parse *p)
{
	t_list	*tmp_call;
	t_list	*tmp_label;

	tmp_call = CALL_LABEL;
	while (CALL_LABEL)
	{
		tmp_label = LABEL;
		while (LABEL && ft_strcmp(LABEL_NAME, CALL_LABEL_NAME))
			LABEL = LABEL_NEXT;
		if (!LABEL)
			error(LABEL_EXIST, CALL_LABEL_NAME);
		else
			add_label_to_arg(p);
		LABEL = tmp_label;
		CALL_LABEL = CALL_LABEL_NEXT;
	}
	CALL_LABEL = tmp_call;
	return (1);
}
