/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_misc_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:43:41 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void			parse_misc_options(t_param *params, int ac, char **av)
{
	int cnt;

	cnt = 0;
	while (cnt++ < ac - 1 && ac != 1)
	{
		if (av[cnt] && !ft_strcmp(av[cnt], "-dump"))
			params->exit_dump = get_options_value("-dump", av[cnt + 1], av[0]);
		else if (av[cnt] && !ft_strcmp(av[cnt], "-s"))
			params->loop_dump = get_options_value("-s", av[cnt + 1], av[0]);
		else if (av[cnt] && !ft_strcmp(av[cnt], "-v"))
			params->verb_lvl = get_options_value("-v", av[cnt + 1], av[0]);
		else if (av[cnt] && !ft_strcmp(av[cnt], "-a"))
		{
			params->disp_aff = TRUE;
			av[cnt] = NULL;
			continue;
		}
		else
			continue;
		av[cnt] = NULL;
		av[cnt + 1] = NULL;
	}
}
