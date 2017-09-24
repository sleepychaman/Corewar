/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 05:51:59 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 15:09:37 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_error.h"
#include "asm_parse.h"

int		main(int ac, char **av)
{
	if (!error_arg(ac, av))
		create_champion(parse(av[1]), av[1]);
	return (0);
}
