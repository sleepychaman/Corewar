/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:22:57 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdio.h>
#include <libft.h>

static void	print_byte(char byte, int color, t_bool is_pc, t_bool is_live)
{
	char	hex[3];

	if (is_pc)
		ft_putstr("\033[");
	else
		ft_putstr("\033[1;");
	if (is_live)
	{
		ft_putnbr(FOREGROUND(color));
		ft_putstr(";107");
	}
	else if (is_pc)
	{
		ft_putstr("30;");
		ft_putnbr(BACKGROUND(color));
	}
	else if (color)
		ft_putnbr(FOREGROUND(color));
	ft_putchar('m');
	byte_to_hex(byte, hex);
	ft_putstr(hex);
	ft_putstr("\033[0m");
}

static void	print_line(t_byte *memory, int verb_lvl)
{
	int		count;
	t_byte	*cur;

	count = 0;
	while (count < TEXT_PRINT_WIDTH)
	{
		cur = &memory[count];
		if (verb_lvl >= VERB_LVL_PC)
			print_byte(cur->content, cur->color, cur->is_pc, cur->is_live);
		else if (verb_lvl >= VERB_LVL_COLOR)
			print_byte(cur->content, cur->color, FALSE, FALSE);
		else
			print_byte(cur->content, 0, FALSE, FALSE);
		count++;
		if (count % 8 == 0 && count < TEXT_PRINT_WIDTH)
			ft_putstr("  ");
		else if (count < TEXT_PRINT_WIDTH)
			ft_putchar(' ');
	}
}

static void	print_ascii(t_byte *memory)
{
	int		count;
	t_byte	*cur;

	count = 0;
	ft_putstr("   ");
	while (count < TEXT_PRINT_WIDTH)
	{
		cur = &memory[count];
		if (ft_isprint(cur->content))
			ft_putchar(cur->content);
		else
			ft_putchar('.');
		count++;
		if (count % 8 == 0 && count < TEXT_PRINT_WIDTH)
			ft_putchar(' ');
	}
}

static void	print_offset_to_hex(short offset)
{
	char	*cast;
	char	hex[3];

	cast = (char *)&offset;
	ft_putstr(" 0x");
	byte_to_hex(cast[1], hex);
	ft_putstr(hex);
	byte_to_hex(cast[0], hex);
	ft_putstr(hex);
	ft_putstr(":   ");
}

void		print_memory(t_byte *memory, int verb_lvl, t_bool pause)
{
	int		count;
	char	buf;

	count = 0;
	ft_putchar('\n');
	while (count < MEM_SIZE)
	{
		if (verb_lvl >= VERB_LVL_OFFSET)
			print_offset_to_hex(count);
		else
			ft_putchar('\t');
		print_line(&memory[count], verb_lvl);
		if (verb_lvl >= VERB_LVL_ASCII)
			print_ascii(&memory[count]);
		ft_putchar('\n');
		count += TEXT_PRINT_WIDTH;
	}
	ft_putchar('\n');
	if (pause)
	{
		ft_putstr("  Press \033[1mENTER\033[0m key to continue ");
		while (read(0, &buf, 1) && buf != '\n' & buf != EOF)
			;
	}
}
