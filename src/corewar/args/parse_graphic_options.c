/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_graphic_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:43:36 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void			parse_graphic_options(t_param *params, int ac, char **av)
{
	int	count;

	count = 0;
	while (count++ < ac)
	{
		if (av[count] && !ft_strcmp(av[count], "-g"))
		{
			params->graphic = TRUE;
			av[count] = NULL;
			if (av[count + 1] && !ft_strcmp(av[count + 1], "--stealth"))
			{
				av[count + 1] = NULL;
				params->hidden_mem = TRUE;
			}
		}
	}
}
