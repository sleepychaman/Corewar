/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 04:54:47 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:10:14 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static int	get_line(t_parse *p)
{
	int		ret;
	char	*tmp;

	p->pos = 0;
	p->line_nbr++;
	p->buf[1] = '\0';
	if (p->line)
		free(p->line);
	p->line = ft_strnew(0);
	while ((ret = read(p->fd, p->buf, 1)) && *p->buf != '\n')
	{
		tmp = p->line;
		p->line = ft_strjoin(p->line, p->buf);
		free(tmp);
	}
	if (!ret)
		return (0);
	return (1);
}

static int	parse_line(t_parse *p)
{
	read_lexem(p);
	if (TYPE == NOTHING)
		return (0);
	if (TYPE == CMD_TYPE)
		parse_cmd(p);
	if (TYPE == LABEL_TYPE)
		parse_label(p);
	if (TYPE == OPCODE_TYPE)
		parse_instruction(p);
	return (1);
}

t_champ		*parse(char *file)
{
	t_parse	p;

	p.champ = new_champion();
	p.label = NULL;
	p.called_label = NULL;
	p.line = NULL;
	p.lexem = NULL;
	p.line_nbr = 0;
	p.last_line = 0;
	p.type = 0;
	p.last_type = 0;
	if ((p.fd = open(file, O_RDONLY)))
		while (get_line(&p))
			while (parse_line(&p))
				;
	add_label(&p);
	return (p.champ);
}
