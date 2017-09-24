/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 15:15:53 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:32 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **begin, t_list *new)
{
	t_list	*tmp;

	tmp = *begin;
	while (begin && tmp && tmp->next)
		tmp = tmp->next;
	if (begin && tmp)
		tmp->next = new;
	else
		*begin = new;
}
