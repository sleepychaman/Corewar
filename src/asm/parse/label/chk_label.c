/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 13:04:03 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:45 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int		chk_label(char *name)
{
	int		i;
	int		j;
	char	*label_chars;

	label_chars = ft_strdup(LABEL_CHARS);
	if (!name || !name[0])
		return (0);
	i = 0;
	while (name[i])
	{
		j = 0;
		while (name[i] != label_chars[j])
		{
			if (!label_chars[j])
				return (0);
			j++;
		}
		i++;
	}
	free(label_chars);
	return (1);
}
