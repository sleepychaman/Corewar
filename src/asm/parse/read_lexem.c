/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 12:59:00 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:10:12 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static int	save_lexem(t_parse *p)
{
	char	*t;
	char	c[2];
	int		i;

	if (LEXEM)
		free(LEXEM);
	LEXEM = ft_strnew(0);
	i = 0;
	c[1] = 0;
	while (LINE(POS)
			&& LINE(POS) != ' ' && LINE(POS) != '\t' && LINE(POS) != ',')
	{
		c[0] = LINE(POS);
		t = LEXEM;
		LEXEM = ft_strjoin(LEXEM, c);
		free(t);
		POS++;
		i++;
	}
	POS -= i;
	return (i--);
}

int			read_lexem_check(t_parse *p, int i)
{
	if (!LINE(POS) || LINE(POS) == COMMENT_CHAR || LINE(POS) == ';')
		TYPE = NOTHING;
	else if (LAST_LINE == LINE_NBR && LAST_TYPE == LABEL_TYPE)
		TYPE = OPCODE_TYPE;
	else if (LINE(POS) == '.')
		TYPE = CMD_TYPE;
	else if (ft_strlen(LEXEM) > 1 && *(&LINE(POS) + i - 1) == LABEL_CHAR)
		TYPE = LABEL_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE && LINE(POS) == 'r')
		TYPE = ARG_REG_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE && LINE(POS) == DIRECT_CHAR)
		TYPE = ARG_DIR_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE
			&& (ft_isdigit(LINE(POS)) || LINE(POS) == LABEL_CHAR
				|| LINE(POS) == '-'))
		TYPE = ARG_IND_TYPE;
	else if (ft_isalpha(LINE(POS)))
		TYPE = OPCODE_TYPE;
	else
		error(INVALID_CHAR, p);
	LAST_LINE = LINE_NBR;
	LAST_TYPE = TYPE;
	return (1);
}

int			read_lexem(t_parse *p)
{
	if (POS != 0 || LINE(POS) == ' ' || LINE(POS) == '\t')
		if (!parse_next(p) && !(TYPE = NOTHING))
			return (0);
	read_lexem_check(p, save_lexem(p));
	return (1);
}
