/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr 		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 07:28:21 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 13:23:02 by ryabicho 	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		error_arg(int ac, char **av)
{
	int		i;

	if (ac > 1 && !(i = 0))
	{
		while (av[1][i] && av[1][i] != '.')
			i++;
		if (av[1][i] == '.' && ft_strcmp(ft_strrchr(av[1], '.'), ".s") == 0)
			if (ft_file_exist(av[1]))
				return (0);
			else
			{
				ft_putstr_fd("asm: ", 2);
				ft_putstr_fd(av[1], 2);
				ft_putstr_fd(": No such file or directory\n", 2);
			}
		else
		{
			ft_putstr_fd("asm: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putstr_fd(": asm file extension are .s\n", 2);
		}
	}
	else
		ft_putstr_fd("asm: No file specified\n", 2);
	return (1);
}
