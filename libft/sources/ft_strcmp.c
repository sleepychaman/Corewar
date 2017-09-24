/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 10:16:19 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:30 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2 && ++s1 && ++s2 && ++i)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
