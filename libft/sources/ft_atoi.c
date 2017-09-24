/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/25 11:05:38 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:07:52 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	n = 0;
	r = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	while ((*str == '-' || *str == '+') && ++i && ++str)
		if (*(str - 1) == '-')
			n++;
	while (*str >= '0' && *str <= '9' && i <= 1)
	{
		r *= 10;
		r += *str - 48;
		str++;
	}
	if (n)
		r *= -1;
	return (r);
}
