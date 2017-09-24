/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_champion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr    		+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:33:11 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 13:19:58 by ryabicho	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

int		del_champion(t_champ *champ)
{
	if (champ->name)
		free(champ->name);
	if (champ->comment)
		free(champ->comment);
	if (champ->bytecode)
		free(champ->bytecode);
	free(champ);
	return (1);
}
