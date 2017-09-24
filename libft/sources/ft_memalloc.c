/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:09:21 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:40 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = (int *)malloc(sizeof(int) * (size + 1));
	if (ptr)
		while (i <= size && (ptr[i] = 0) == 0)
			++i;
	return ((void *)ptr);
}
