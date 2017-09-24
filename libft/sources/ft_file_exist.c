/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 07:29:05 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:08:44 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		ft_file_exist(const char *path)
{
	struct stat	s;

	if (lstat(path, &s) == 0)
		return (1);
	return (0);
}
