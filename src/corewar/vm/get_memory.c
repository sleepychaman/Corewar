/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 14:45:21 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		get_adress(int adress)
{
	adress %= MEM_SIZE;
	if (adress < 0)
		adress += MEM_SIZE;
	return (adress);
}

t_byte	*get_memory(t_byte *memory, int index)
{
	index = get_adress(index);
	return (&memory[index]);
}

int		get_int_memory(t_byte *memory, int index)
{
	char	cast[4];
	int		count;

	count = 0;
	while (count < 4)
	{
		cast[count] = memory[(index + count) % MEM_SIZE].content;
		count++;
	}
	return (*(int *)&cast);
}

void	put_int_memory(t_byte *memory, int index, int put, int color)
{
	char	*cast;
	int		count;

	count = 0;
	cast = (char *)&put;
	while (count < 4)
	{
		memory[(index + count) % MEM_SIZE].content = cast[count];
		memory[(index + count) % MEM_SIZE].color = color;
		count++;
	}
}

int		calc_indirect(int prog_count, int offset)
{
	int	ret;

	ret = prog_count + (offset % IDX_MOD);
	ret = get_adress(ret);
	return (ret);
}
