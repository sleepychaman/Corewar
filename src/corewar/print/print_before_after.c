/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_before_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:43:46 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void	print_players_intro(t_param *params)
{
	int	count;

	count = 0;
	while (count < params->champs_amount)
	{
		ft_putstr("Player #");
		ft_putnbr(params->champs[count].number);
		ft_putstr(" \033[1;");
		ft_putnbr(FOREGROUND(count + 1));
		ft_putchar('m');
		ft_putstr(params->champs[count].header.prog_name);
		ft_putstr("\033[0m");
		ft_putstr(" weighing ");
		ft_putnbr(params->champs[count].header.prog_size);
		ft_putstr(" bytes, says: ");
		ft_putstr(" \033[1m");
		ft_putendl(params->champs[count].header.comment);
		ft_putstr("\033[0m");
		count++;
	}
}

void	print_winner(t_param *params, t_vm_data *data)
{
	int	count;

	if (data->last_champ_alive != UNSET)
	{
		count = 0;
		while (count < params->champs_amount)
		{
			if (data->last_champ_alive == params->champs[count].number)
			{
				ft_putstr("\nle joueur ");
				ft_putnbr(params->champs[count].number);
				ft_putchar('(');
				ft_putstr(params->champs[count].header.prog_name);
				ft_putchar(')');
				ft_putendl(" a gagne");
				return ;
			}
			count++;
		}
	}
}
