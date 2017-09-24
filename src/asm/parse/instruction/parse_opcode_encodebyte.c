/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opcode_encodebyte.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:42:34 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:39 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static int	parse_opcode_encodebyte_add(t_parse *p, char encode[3])
{
	char	byte;

	byte = 0;
	byte += encode[0] << 6;
	if (encode[1] != 0)
		byte += encode[1] << 4;
	if (encode[2] != 0)
		byte += encode[2] << 2;
	add_bytecode(CHAMPION, byte);
	return (1);
}

int			parse_opcode_encodebyte(t_parse *p, t_op op)
{
	int		i;
	char	encode[4];
	int		op_parsepos;

	op_parsepos = POS;
	i = 0;
	while (i < op.arg_nbr)
	{
		LAST_TYPE = OPCODE_TYPE;
		read_lexem(p);
		if (TYPE == ARG_REG_TYPE && (op.arg_type[i] & T_REG))
			encode[i] = REG_CODE;
		else if (TYPE == ARG_DIR_TYPE && (op.arg_type[i] & T_DIR))
			encode[i] = DIR_CODE;
		else if (TYPE == ARG_IND_TYPE && (op.arg_type[i] & T_IND))
			encode[i] = IND_CODE;
		else if (TYPE == NOTHING)
			error(INVALID_CHAR, p);
		else
			error(ARG, p);
		i++;
	}
	encode[i] = 0;
	POS = op_parsepos;
	return (parse_opcode_encodebyte_add(p, encode));
}
