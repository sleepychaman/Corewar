/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 07:32:38 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:05 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERROR_H
# define ASM_ERROR_H

# include <libft.h>
# include "asm_parse.h"

typedef enum	e_error
{
	CMD,
	CMD_STRING_LENGTH,
	INVALID_CHAR,
	LABEL_NAMED,
	LABEL_EXIST,
	MNEMONIC,
	ARG,
}				t_error;

int		error(t_error e, void *p);
int		error_part_two(t_error e, void *p);
int		error_arg(int ac, char **av);

#endif
