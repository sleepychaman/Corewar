# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabicho <ryabicho@student.42.fr  			+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 13:15:49 by ryabicho          #+#    #+#              #
#    Updated: 2017/09/22 13:16:20 by ryabicho      	  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(INCS_DIR)
AR				=	ar
ARFLAGS			=	rc
INCS_DIR		=	./includes
OBJS_DIR		=	./objs
SRCS_DIR		=	./srcs
OBJS			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
SRCS			=	ft_strlen.c ft_strnew.c ft_strdup.c ft_strjoin.c				\
					ft_strcpy.c ft_strrchr.c ft_strcmp.c ft_strncmp.c				\
					ft_isdigit.c ft_isalpha.c ft_isprint.c							\
					ft_lstnew.c ft_lstadd.c											\
					ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c				\
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
					ft_bzero.c ft_memalloc.c ft_memcpy.c							\
					ft_atoi.c ft_revint32.c ft_file_exist.c

all				:	$(NAME)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "]   \033[1;32mDone\033[0;0m\n"

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	@$(CC) $(CFLAGS) -o $@ -c $^
	@printf "."

$(OBJS_DIR)		:
	@mkdir -p $(OBJS_DIR)
	@printf "\033[1;32mCompiling libft   \033[0;0m["

fclean			:	clean
	@rm -f $(NAME)
	@printf "\033[1;31mCompiled libft deleted\033[0;0m\n"

clean			:
	@rm -rf $(OBJS_DIR)
	@printf "\033[1;31mObjects deleted\033[0;0m\n"

re				:	fclean all

.PHONY: clean all re fclean
