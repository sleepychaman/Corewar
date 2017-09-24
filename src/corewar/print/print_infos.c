/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:43:50 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void	print_turn(t_param *params, t_vm_data *data)
{
	if (params->verb_lvl >= VERB_LVL_CYCLES)
	{
		ft_putstr("\n--- Cycle #");
		ft_putnbr(data->cycle_count);
		ft_putendl(" -----------------------------------------------------");
	}
	if (params->loop_dump > 0 && data->cycle_count
		&& !(data->cycle_count % params->loop_dump))
		print_memory(data->memory, params->verb_lvl, TRUE);
}

void	print_death(int count, t_param *params)
{
	ft_putstr("Player #");
	ft_putnbr(params->champs[count].number);
	ft_putstr(" \033[1;");
	ft_putnbr(FOREGROUND(count + 1));
	ft_putchar('m');
	ft_putstr(params->champs[count].header.prog_name);
	ft_putstr("\033[0m");
	ft_putendl(" is dead");
}

void	print_live(int caller, int pid)
{
	ft_putstr("Player #");
	ft_putnbr(caller);
	ft_putstr(" says: \"");
	if (caller == pid)
		ft_putstr("I am");
	else
	{
		ft_putstr("Player #");
		ft_putnbr(pid);
		ft_putstr(" is");
	}
	ft_putendl(" alive\"");
}

void	print_operation(t_process *process)
{
	int	count;

	count = 0;
	ft_putstr("Player #");
	ft_putnbr(*(int *)&process->reg[0]);
	ft_putstr(": ");
	ft_putstr(" \033[1m");
	ft_putstr(process->instruction.name);
	ft_putstr("\033[0m");
	while (count < MAX_PARAMS && process->instruction.type[count] != UNSET)
	{
		if (count)
			ft_putchar(',');
		ft_putchar(' ');
		if (process->instruction.type[count] == REG_CODE)
			ft_putchar('r');
		ft_putnbr(process->instruction.value[count]);
		count++;
	}
	ft_putchar('\n');
}
