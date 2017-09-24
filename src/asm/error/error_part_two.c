/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:56:35 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:19:56 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static void	error_instruct_arg(t_parse *p)
{
	ft_putstr_fd("asm: Invalid argument \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_label_name(t_parse *p)
{
	ft_putstr_fd("asm: Invalid label name \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_label_exist(char *p)
{
	ft_putstr_fd("asm: Label \"", 2);
	ft_putstr_fd(p, 2);
	ft_putstr_fd("\" does not exist\n", 2);
}

int			error_part_two(enum e_error e, void *p)
{
	if (e == ARG)
		error_instruct_arg(p);
	if (e == LABEL_NAMED)
		error_label_name(p);
	if (e == LABEL_EXIST)
		error_label_exist(p);
	return (0);
}
