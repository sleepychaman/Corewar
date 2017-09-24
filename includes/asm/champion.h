/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:28:22 by ryabicho          #+#    #+#             */
/*   Updated: 2017/09/22 14:20:19 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_champ
{
	char			*name;
	char			*comment;
	char			*bytecode;
	int				len;
}					t_champ;

t_champ				*new_champion(void);
int					del_champion(t_champ *champ);
int					add_bytecode(t_champ *champ, char byte);
int					create_champion(t_champ *champ, char *filename);

#endif
