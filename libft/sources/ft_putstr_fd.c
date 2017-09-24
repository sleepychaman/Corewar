/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:05:52 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:24 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr && write(fd, ptr, 1) && ++ptr)
		;
}
