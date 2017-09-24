/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:11:34 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:14 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)s;
	i = ft_strlen(s);
	while (i != -1)
	{
		if (ptr[i] == (unsigned char)c)
			return ((char *)&ptr[i]);
		i--;
	}
	return (NULL);
}
