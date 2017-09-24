# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabicho <ryabicho@student.42.fr    		+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 11:11:35 by ryabicho     	   #+#    #+#              #
#    Updated: 2017/09/22 11:11:35 by ryabicho      	  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	corewar
NAME2			=	asm

CC				=	clang
GDB				?=	0
ifeq ($(GDB), 1)
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -g3 -I $(LIBFT_INCS_DIR)
else
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -O3 -I $(LIBFT_INCS_DIR)
endif
LFLAGS			=	-L $(LIBFT_DIR) -lft

INCS_DIR		=	./includes
LIBFT_DIR		=	./libft
LIBFT_INCS_DIR	=	$(LIBFT_DIR)/includes

SRCS_DIR		=	./src
OBJS_DIR		=	./objs

INCS_CW_DIR		=	$(INCS_DIR)/corewar

SRCS_CW_DIR		=	$(SRCS_DIR)/corewar
SRCS_CW			=	main.c							\
					byte_to_hex.c					\
					exit_error.c					\
					args/parse_args.c				\
					args/parse_champs_options.c		\
					args/parse_graphic_options.c	\
					args/parse_misc_options.c		\
					vm/exec_virtual_machine.c		\
					vm/launch_virtual_machine.c		\
					vm/get_memory.c					\
					vm/parse_files.c				\
					vm/process_list.c				\
					vm/cycle/instruction_cycle.c	\
					vm/cycle/fetch_instruction.c	\
					vm/cycle/decode_instruction.c	\
					vm/cycle/execute_instruction.c	\
					vm/operations/op_add.c			\
					vm/operations/op_aff.c			\
					vm/operations/op_and.c			\
					vm/operations/op_fork.c			\
					vm/operations/op_ld.c			\
					vm/operations/op_ldi.c			\
					vm/operations/op_lfork.c		\
					vm/operations/op_live.c			\
					vm/operations/op_lld.c			\
					vm/operations/op_lldi.c			\
					vm/operations/op_or.c			\
					vm/operations/op_st.c			\
					vm/operations/op_sti.c			\
					vm/operations/op_sub.c			\
					vm/operations/op_xor.c			\
					vm/operations/op_zjmp.c			\
					print/print_before_after.c		\
					print/print_infos.c				\
					print/print_memory.c

OBJS_CW_DIR		=	$(OBJS_DIR)/corewar
OBJS_CW			=	$(patsubst %.c, $(OBJS_CW_DIR)/%.o, $(SRCS_CW))

INCS_AS_DIR		=	$(INCS_DIR)/asm

SRCS_AS_DIR		=	$(SRCS_DIR)/asm
SRCS_AS			=	main.c										\
					op.c										\
					champion/add_bytecode.c						\
					champion/create_champion.c					\
					champion/del_champion.c						\
					champion/new_champion.c						\
					error/error_arg.c							\
					error/error.c								\
					error/error_part_two.c						\
					parse/parse.c								\
					parse/parse_cmd.c							\
					parse/parse_next.c							\
					parse/read_lexem.c							\
					parse/instruction/parse_arg_dir.c			\
					parse/instruction/parse_arg_ind.c			\
					parse/instruction/parse_arg_reg.c			\
					parse/instruction/parse_instruction.c		\
					parse/instruction/parse_opcode.c			\
					parse/instruction/parse_opcode_encodebyte.c	\
					parse/label/add_label.c						\
					parse/label/call_label.c					\
					parse/label/chk_label.c						\
					parse/label/parse_label.c

OBJS_AS_DIR		=	$(OBJS_DIR)/asm
OBJS_AS			=	$(patsubst %.c, $(OBJS_AS_DIR)/%.o, $(SRCS_AS))

COL_ON		=	\033[30;47m
COL_OFF		=	\033[0m

all				:	$(NAME) $(NAME2)

$(NAME)			:	$(OBJS_DIR) $(OBJS_CW)
	$(CC) -o $(NAME) $(OBJS_CW) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS_AS)
	$(CC) -o $(NAME2) $(OBJS_AS) $(LFLAGS)

$(OBJS_CW_DIR)/%.o	:	$(addprefix $(SRCS_CW_DIR)/, %.c)
	$(CC) $(CFLAGS) -I $(INCS_CW_DIR) -o $@ -c $^

$(OBJS_AS_DIR)/%.o	:	$(addprefix $(SRCS_AS_DIR)/, %.c)
	$(CC) $(CFLAGS) -I $(INCS_AS_DIR) -o $@ -c $^

$(OBJS_DIR)		:	make_libft
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_CW_DIR)
	@mkdir -p $(OBJS_CW_DIR)/args
	@mkdir -p $(OBJS_CW_DIR)/vm
	@mkdir -p $(OBJS_CW_DIR)/vm/operations
	@mkdir -p $(OBJS_CW_DIR)/vm/cycle
	@mkdir -p $(OBJS_CW_DIR)/print
	@mkdir -p $(OBJS_AS_DIR)
	@mkdir -p $(OBJS_AS_DIR)/champion
	@mkdir -p $(OBJS_AS_DIR)/error
	@mkdir -p $(OBJS_AS_DIR)/parse
	@mkdir -p $(OBJS_AS_DIR)/parse/instruction
	@mkdir -p $(OBJS_AS_DIR)/parse/label

make_libft		:
	$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
