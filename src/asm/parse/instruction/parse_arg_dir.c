/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:47:43 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:42 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static int	parse_arg_dir_has_idx(t_parse *p, int op_bytepos)
{
	int		i;

	TYPE = ARG_IND_TYPE;
	i = 1;
	while (LEXEM[i] && (ft_isdigit(LEXEM[i]) || (i = 1 && LEXEM[i] == '-')))
		i++;
	if (i > 1 && !LEXEM[i])
	{
		i = ft_atoi(&LEXEM[1]);
		add_bytecode(CHAMPION, i >> 8 & 0xFF);
		add_bytecode(CHAMPION, i & 0xFF);
	}
	else if (LEXEM[1] == ':' && chk_label(&LEXEM[2]))
	{
		call_label(p, &LEXEM[2], op_bytepos);
		add_bytecode(CHAMPION, 0);
		add_bytecode(CHAMPION, 0);
	}
	else
		error(ARG, p);
	return (1);
}

int			parse_arg_dir_hasnt_idx(t_parse *p, int op_bytepos)
{
	int		i;

	i = 1;
	while (LEXEM[i] && (ft_isdigit(LEXEM[i]) || (i = 1 && LEXEM[i] == '-')))
		i++;
	if (i > 1 && !LEXEM[i])
	{
		i = ft_atoi(&LEXEM[1]);
		add_bytecode(CHAMPION, i >> 24 & 0xFF);
		add_bytecode(CHAMPION, i >> 16 & 0xFF);
		add_bytecode(CHAMPION, i >> 8 & 0xFF);
		add_bytecode(CHAMPION, i & 0xFF);
	}
	else if (LEXEM[1] == ':' && chk_label(&LEXEM[2]))
	{
		call_label(p, &LEXEM[2], op_bytepos);
		add_bytecode(CHAMPION, 0);
		add_bytecode(CHAMPION, 0);
		add_bytecode(CHAMPION, 0);
		add_bytecode(CHAMPION, 0);
	}
	else
		error(ARG, p);
	return (1);
}

int			parse_arg_dir(t_parse *p, int op_bytepos, t_op op)
{
	if (op.has_idx)
		parse_arg_dir_has_idx(p, op_bytepos);
	else
		parse_arg_dir_hasnt_idx(p, op_bytepos);
	return (1);
}
