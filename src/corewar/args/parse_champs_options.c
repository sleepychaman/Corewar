/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:22:22 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static int	get_champ_number(t_param *params, int index)
{
	int	count;
	int	number;

	count = 0;
	number = 1;
	while (count < index)
	{
		if (number == params->champs[count].number)
		{
			number++;
			count = 0;
		}
		else
			count++;
	}
	return (number);
}

static void	set_champ(t_param *params, int index, char *path, int number)
{
	if (number == -1)
		number = get_champ_number(params, index);
	params->champs[index].path = path;
	params->champs[index].number = number;
	params->champs[index].process = 0;
	params->champs[index].color = index + 1;
}

static int	parse_champs_with_flag(t_param *params, int ac, char **av)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (count++ < ac && index < MAX_PLAYERS)
	{
		if (av[count] && !ft_strcmp(av[count], "-n") && count + 2 < ac
			&& av[count + 1] && av[count + 2])
		{
			set_champ(params, index, av[count + 2],
					get_options_value("-n", av[count + 1], params->ex_path));
			av[count + 1] = NULL;
			av[count + 2] = NULL;
		}
		else if (av[count] && !ft_strcmp(av[count], "-n"))
			exit_error("-n", "specify a number and a file", params->ex_path);
		else if (av[count])
			set_champ(params, index, av[count], -1);
		else
			continue;
		av[count] = NULL;
		index++;
	}
	return (index);
}

static void	find_champ_number_dup(t_param *params, int index)
{
	int	count;
	int	count2;

	count = 0;
	while (count < index - 1)
	{
		count2 = count + 1;
		while (count2 < index)
		{
			if (params->champs[count].number == params->champs[count2].number)
				exit_error("Champions", "can't set same number twice",
							params->ex_path);
			count2++;
		}
		count++;
	}
}

void		parse_champs_options(t_param *params, int ac, char **av)
{
	int	count;
	int	index;

	count = 0;
	index = parse_champs_with_flag(params, ac, av);
	while (count++ < ac)
	{
		if (av[count])
			exit_error("Champions", "specify not more than four",
						params->ex_path);
	}
	if (!index)
		exit_error("Champions", "specify at least one",
					params->ex_path);
	if (index > 1)
		find_champ_number_dup(params, index);
	params->champs_amount = index;
}
