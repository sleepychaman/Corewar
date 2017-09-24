/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 02:19:32 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:10:13 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_error.h"
#include "asm_parse.h"

static int	parse_cmd_string_name(t_parse *p)
{
	char	*s;
	char	*t;
	char	c[2];

	if (p->champ->name)
		free(p->champ->name);
	c[1] = '\0';
	if (LINE(POS) != '"')
		error(INVALID_CHAR, p);
	s = ft_strdup("");
	POS++;
	while (LINE(POS) && LINE(POS) != '"')
	{
		t = s;
		c[0] = LINE(POS);
		s = ft_strjoin(s, c);
		free(t);
		POS++;
	}
	if (LINE(POS) == '"')
		p->champ->name = ft_strdup(s);
	free(s);
	if (LINE(POS) == '\0')
		error(INVALID_CHAR, p);
	return (1);
}

static int	parse_cmd_string_comment(t_parse *p)
{
	char	*s;
	char	*t;
	char	c[2];

	if (p->champ->comment)
		free(p->champ->comment);
	c[1] = '\0';
	if (LINE(POS) != '"')
		error(INVALID_CHAR, p);
	s = ft_strdup("");
	POS++;
	while (LINE(POS) && LINE(POS) != '"' && (t = s))
	{
		c[0] = LINE(POS);
		s = ft_strjoin(s, c);
		free(t);
		POS++;
	}
	if (LINE(POS) == '\0' && (s = ft_strjoin(s, "\n")))
		while (read(p->fd, &c, 1) && c[0] != '"' && (t = s)
			&& (s = ft_strjoin(s, c)))
			free(t);
	p->champ->comment = ft_strdup(s);
	free(s);
	return (1);
}

int			parse_cmd(t_parse *p)
{
	if (ft_strncmp(&LINE(POS), NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) == 0 && parse_next(p))
	{
		parse_cmd_string_name(p);
		if (ft_strlen(p->champ->name) > PROG_NAME_LENGTH)
			error(CMD_STRING_LENGTH, p);
	}
	else if (ft_strncmp(&LINE(POS), COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0 && parse_next(p))
	{
		parse_cmd_string_comment(p);
		if (ft_strlen(p->champ->comment) > COMMENT_LENGTH)
			error(CMD_STRING_LENGTH, p);
	}
	else
		error(CMD, p);
	POS++;
	if (LINE(POS))
		error(INVALID_CHAR, p);
	return (1);
}
