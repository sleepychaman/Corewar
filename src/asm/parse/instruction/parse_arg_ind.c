/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:48:34 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:43 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int		parse_arg_ind(t_parse *p, int op_bytepos)
{
	int		i;

	i = 0;
	while (LEXEM[i] && (ft_isdigit(LEXEM[i]) || (i == 0 && LEXEM[i] == '-')))
		i++;
	if (i > 0 && !LEXEM[i])
	{
		i = ft_atoi(LEXEM);
		add_bytecode(CHAMPION, i >> 8 & 0xFF);
		add_bytecode(CHAMPION, i & 0xFF);
	}
	else if (LEXEM[0] == ':' && chk_label(&LEXEM[1]))
	{
		call_label(p, &LEXEM[1], op_bytepos);
		add_bytecode(CHAMPION, 0);
		add_bytecode(CHAMPION, 0);
	}
	else
		error(ARG, p);
	return (1);
}
