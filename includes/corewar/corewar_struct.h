/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <ryabicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:03:07 by ryabicho             #+#    #+#             */
/*   Updated: 2015/09/19 15:45:04 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

# include <values.h>

typedef long long unsigned int	t_llui;

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef struct		s_byte
{
	char			content;
	int				color;
	t_bool			is_pc;
	t_bool			is_live;
}					t_byte;

typedef	struct		s_fetched
{
	int				op_code;
	char			*name;
	int				type[3];
	int				size[3];
	int				value[3];
	int				pc_gap;
}					t_fetched;

typedef struct		s_op
{
	char			*mnemonic;
	int				arg_nbr;
	int				arg_type[3];
	int				op_code;
	int				cycle;
	char			*description;
	int				encoding;
	int				has_idx;
}					t_op;

typedef struct		s_process
{
	int				prog_count;
	char			reg[REG_NUMBER][REG_SIZE];
	int				cycle_rest;
	t_fetched		instruction;
	t_bool			carry;
	t_bool			alive;
}					t_process;

typedef struct		s_plist
{
	t_process		process;
	struct s_plist	*next;
	struct s_plist	*prev;
}					t_plist;

typedef struct		s_vm_data
{
	int				cycle_to_die;
	t_llui			cycle_count;
	int				last_check;
	int				check_count;
	int				nb_live_champs[MAX_PLAYERS];
	int				nb_proc_champs[MAX_PLAYERS];
	int				last_champ_alive;
	t_byte			memory[MEM_SIZE];
	t_plist			*head;
}					t_vm_data;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_champ
{
	char			*path;
	int				number;
	t_header		header;
	char			*code;
	int				process;
	int				color;
}					t_champ;

typedef struct		s_param
{
	char			*ex_path;
	int				exit_dump;
	int				loop_dump;
	int				verb_lvl;
	t_bool			graphic;
	t_bool			hidden_mem;
	t_bool			disp_aff;
	t_champ			champs[MAX_PLAYERS];
	int				champs_amount;
}					t_param;

#endif
