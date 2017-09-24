/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:44:44 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:40 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

t_op	parse_opcode(t_parse *p)
{
	extern t_op	op_tab[];
	int			i;

	i = 0;
	while (op_tab[i].mnemonic && ft_strcmp(LEXEM, op_tab[i].mnemonic))
		i++;
	if (op_tab[i].mnemonic == 0)
		error(MNEMONIC, p);
	if (POS == 0)
		POS++;
	add_bytecode(CHAMPION, op_tab[i].op_code);
	if (op_tab[i].encoding)
		parse_opcode_encodebyte(p, op_tab[i]);
	return (op_tab[i]);
}
