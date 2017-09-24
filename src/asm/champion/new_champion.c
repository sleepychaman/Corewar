/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_champion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabichon <ryabichon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:31:30 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 13:21:31 by ryabicho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

t_champ		*new_champion(void)
{
	t_champ		*champ;

	champ = (t_champ *)malloc(sizeof(t_champ));
	champ->name = NULL;
	champ->comment = NULL;
	champ->bytecode = NULL;
	champ->len = 0;
	return (champ);
}
