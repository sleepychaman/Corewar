/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_virtual_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:28:12 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static int		sum_and_wipe_array(int *array, int size, t_bool wipe)
{
	int	acc;
	int	count;

	acc = 0;
	count = 0;
	while (count < size)
	{
		acc += array[count];
		if (wipe)
			array[count] = 0;
		count++;
	}
	return (acc);
}

static void		delete_dead_process(t_param *params, t_vm_data *data)
{
	t_plist	*iter;
	t_plist	*to_free;
	int		count;

	iter = data->head->next;
	count = 0;
	while (iter)
	{
		to_free = iter;
		iter = iter->next;
		if (to_free->process.alive)
			to_free->process.alive = FALSE;
		else
			delete_process(to_free);
	}
	while (count < params->champs_amount)
	{
		data->nb_proc_champs[count] = count_list(data->head,
												params->champs[count].number);
		if (!data->nb_proc_champs[count] && !params->graphic
			&& params->verb_lvl >= VERB_LVL_DEATH)
			print_death(count, params);
		count++;
	}
}

static t_bool	check_fight_state(t_param *params, t_vm_data *data)
{
	unsigned int	total_live;
	unsigned int	total_proc;

	if (data->last_check >= data->cycle_to_die)
	{
		data->last_check = 0;
		data->check_count++;
		total_live = sum_and_wipe_array(data->nb_live_champs, 4, TRUE);
		if (data->check_count >= MAX_CHECKS || total_live >= NBR_LIVE)
		{
			data->cycle_to_die -= CYCLE_DELTA;
			data->check_count = 0;
		}
		delete_dead_process(params, data);
	}
	total_proc = sum_and_wipe_array(data->nb_proc_champs, 4, FALSE);
	if (!total_proc)
		return (FALSE);
	data->last_check++;
	return (TRUE);
}

void			exec_virtual_machine(t_param *params, t_vm_data *data)
{
	while (42)
	{
		if (!params->graphic)
		{
			if (params->verb_lvl >= VERB_LVL_CYCLES)
				print_turn(params, data);
			if (data->cycle_count >= (t_llui)params->exit_dump)
			{
				print_memory(data->memory, params->verb_lvl, FALSE);
				data->last_champ_alive = UNSET;
				return ;
			}
		}
		data->cycle_count++;
		instruction_cycle(params, data);
		if (!check_fight_state(params, data))
			return ;
	}
}
