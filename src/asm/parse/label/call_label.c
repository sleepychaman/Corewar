/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 12:55:41 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:52 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int		call_label(t_parse *p, char *name, int op_bytepos)
{
	t_list	*label;
	t_list	*new_call;

	label = ft_lstnew(name, ft_strlen(name));
	label->content_size = op_bytepos;
	new_call = ft_lstnew(label, sizeof(t_list));
	if (TYPE == ARG_DIR_TYPE)
		new_call->content_size = CHAMPION->len;
	else
		new_call->content_size = -CHAMPION->len;
	ft_lstadd(&CALL_LABEL, new_call);
	return (1);
}
