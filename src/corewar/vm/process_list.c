/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:24:43 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_struct.h>
#include <stdlib.h>

void	new_process(t_process proc, t_plist *head)
{
	t_plist	*new;

	new = (t_plist *)malloc(sizeof(t_plist));
	new->process = proc;
	new->next = head->next;
	new->prev = head;
	head->next = new;
	if (new->next)
		new->next->prev = new;
}

void	delete_process(t_plist *elem)
{
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}

void	free_list(t_plist *head)
{
	t_plist *iter;
	t_plist *to_free;

	iter = head;
	while (iter)
	{
		to_free = iter;
		iter = iter->next;
		free(to_free);
	}
}

int		count_list(t_plist *head, int player)
{
	int		count;
	t_plist *iter;

	count = 0;
	iter = head;
	while (iter)
	{
		if (player)
		{
			if (player == *(int *)&iter->process.reg[0])
				count++;
		}
		else
			count++;
		iter = iter->next;
	}
	return (count);
}
