/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:56:35 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:10:09 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static void	error_cmd_type(t_parse *p)
{
	ft_putstr_fd("asm: Invalid cmd type, line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_char(t_parse *p)
{
	if (LINE(POS))
	{
		ft_putstr_fd("asm: Invalid character '", 2);
		ft_putchar_fd(LINE(POS), 2);
		ft_putstr_fd("', line : ", 2);
	}
	else
		ft_putstr_fd("asm: Invalid end of line, line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_cmd_string_length(t_parse *p)
{
	ft_putstr_fd("asm: cmd string too long line : '", 2);
	ft_putchar_fd(LINE(POS), 2);
	ft_putstr_fd("', line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_mnemonic(t_parse *p)
{
	ft_putstr_fd("asm: Invalid mnemonic \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

int			error(enum e_error e, void *p)
{
	if (e == CMD)
		error_cmd_type(p);
	if (e == CMD_STRING_LENGTH)
		error_cmd_string_length(p);
	if (e == INVALID_CHAR)
		error_char(p);
	if (e == MNEMONIC)
		error_mnemonic(p);
	error_part_two(e, p);
	exit(0);
	return (1);
}
