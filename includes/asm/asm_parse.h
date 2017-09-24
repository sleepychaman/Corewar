/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 05:15:58 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:13 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSE_H
# define ASM_PARSE_H

# include <op.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft.h>
# include "champion.h"

typedef enum	e_type
{
	NOTHING,
	CMD_TYPE,
	LABEL_TYPE,
	OPCODE_TYPE,
	ARG_REG_TYPE,
	ARG_DIR_TYPE,
	ARG_IND_TYPE,
}				t_type;

typedef struct	s_parse
{
	t_champ		*champ;
	int			fd;
	char		buf[2];
	char		*line;
	int			line_nbr;
	int			last_line;
	int			pos;
	char		*lexem;
	t_type		type;
	t_type		last_type;
	t_list		*label;
	t_list		*called_label;
	int			i;
}				t_parse;

t_champ			*parse(char *file);
int				parse_next(t_parse *p);
int				read_lexem(t_parse *p);
int				parse_cmd(t_parse *p);

int				parse_label(t_parse *p);
int				chk_label(char *name);
int				call_label(t_parse *p, char *name, int op_bytepos);
int				add_label(t_parse *p);

int				parse_instruction(t_parse *p);
t_op			parse_opcode(t_parse *p);
int				parse_opcode_encodebyte(t_parse *p, t_op op);
int				parse_arg_reg(t_parse *p);
int				parse_arg_dir(t_parse *p, int op_bytepos, t_op op);
int				parse_arg_ind(t_parse *p, int op_bytepos);

# define LINE_NBR p->line_nbr
# define LAST_LINE p->last_line
# define LINE(POS) p->line[p->pos]
# define POS p->pos
# define TYPE p->type
# define LAST_TYPE p->last_type
# define LEXEM p->lexem
# define CHAMPION p->champ
# define LABEL p->label
# define LABEL_NAME p->label->content
# define LABEL_INDEX p->label->content_size
# define LABEL_NEXT p->label->next
# define CALL_LABEL p->called_label
# define CALL_LABEL_NAME ((t_list *)p->called_label->content)->content
# define CALL_LABEL_OPINDEX ((t_list *)p->called_label->content)->content_size
# define CALL_LABEL_ARGINDEX p->called_label->content_size
# define CALL_LABEL_NEXT p->called_label->next

#endif
