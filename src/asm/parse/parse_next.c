/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:44:44 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:10:11 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

int		parse_next(t_parse *p)
{
	while (LINE(POS) && LINE(POS) != ' ' && LINE(POS) != '\t'
		&& LINE(POS) != ',')
		POS++;
	while (LINE(POS) && (LINE(POS) == ' ' || LINE(POS) == '\t'
		|| LINE(POS) == ','))
		POS++;
	if (LINE(POS) && LINE(POS) != ';')
		return (1);
	return (0);
}
