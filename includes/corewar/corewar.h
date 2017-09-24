/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleepychaman <sleepychaman@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:02:50 by ryabicho             #+#    #+#             */
/*   Updated: 2017/09/22 14:20:10 by sleepychama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <corewar_struct.h>

# define UNSET			-1

# define FOREGROUND(x)	(x + 30)
# define BACKGROUND(x)	(x + 40)

/*
**	Parameters functions
*/
void	parse_args(t_param *params, int ac, char **av);
t_bool	is_number(char *value);
int		get_options_value(char *flag, char *value, char *ex_path);
void	parse_misc_options(t_param *params, int ac, char **av);
void	parse_graphic_options(t_param *params, int ac, char **av);
void	parse_champs_options(t_param *params, int ac, char **av);

/*
**	Process list functions
*/
void	new_process(t_process proc, t_plist *head);
void	delete_process(t_plist *elem);
void	free_list(t_plist *head);
int		count_list(t_plist *head, int player);

/*
**	Virtual machine functions
*/
void	launch_virtual_machine(t_param *params);
void	exec_virtual_machine(t_param *params, t_vm_data *data);
t_byte	*get_memory(t_byte *memory, int index);
int		get_int_memory(t_byte *memory, int index);
void	put_int_memory(t_byte *memory, int index, int put, int color);
int		calc_indirect(int prog_count, int offset);
int		get_adress(int adress);

/*
**	Instruction cycle functions
*/
void	instruction_cycle(t_param *params, t_vm_data *data);
t_op	*get_op_detail(int op_code);
void	reset_instruction(t_process *process, t_bool carry);
void	fetch_instruction(t_process *process, t_byte *memory);
void	decode_instruction(t_process *process, t_byte *memory);
void	execute_instruction(t_process *proc, t_param *params, t_vm_data *data);

/*
**	Operations functions
*/
void	op_live(t_process *process, t_param *params, t_vm_data *data);
void	op_ld(t_process *process, t_param *params, t_vm_data *data);
void	op_st(t_process *process, t_param *params, t_vm_data *data);
void	op_add(t_process *process, t_param *params, t_vm_data *data);
void	op_sub(t_process *process, t_param *params, t_vm_data *data);
void	op_and(t_process *process, t_param *params, t_vm_data *data);
void	op_or(t_process *process, t_param *params, t_vm_data *data);
void	op_xor(t_process *process, t_param *params, t_vm_data *data);
void	op_zjmp(t_process *process, t_param *params, t_vm_data *data);
void	op_ldi(t_process *process, t_param *params, t_vm_data *data);
void	op_sti(t_process *process, t_param *params, t_vm_data *data);
void	op_fork(t_process *process, t_param *params, t_vm_data *data);
void	op_lld(t_process *process, t_param *params, t_vm_data *data);
void	op_lldi(t_process *process, t_param *params, t_vm_data *data);
void	op_lfork(t_process *process, t_param *params, t_vm_data *data);
void	op_aff(t_process *process, t_param *params, t_vm_data *data);

/*
**	Text mode functions
*/
void	print_memory(t_byte *memory, int verb_lvl, t_bool pause);
void	print_players_intro(t_param *params);
void	print_turn(t_param *params, t_vm_data *data);
void	print_death(int count, t_param *params);
void	print_live(int caller, int pid);
void	print_operation(t_process *process);
void	print_winner(t_param *params, t_vm_data *data);

/*
**	Misc functions
*/
void	parse_files(t_param *params);
void	byte_to_hex(char byte, char hex[3]);
void	exit_error(char *error, char *detail, char *ex_path);

#endif
