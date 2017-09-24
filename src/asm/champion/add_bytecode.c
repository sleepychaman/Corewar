/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr    		+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:16:12 by ryabicho      	   #+#    #+#             */
/*   Updated: 2017/09/22 13:16:18 by ryabicho      	  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

int		add_bytecode(t_champ *champion, char byte)
{
	char	c[2];

	if (!champion->bytecode)
		champion->bytecode = (char *)ft_memalloc(1024);
	if (champion->len >= 1024)
	{
		c[1] = 0;
		c[0] = byte;
		ft_strjoin(champion->bytecode, c);
	}
	else
	{
		champion->bytecode[champion->len] = byte;
		champion->len++;
	}
	return (1);
}
