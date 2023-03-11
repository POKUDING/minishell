# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisulee <jisulee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:36:43 by junhyupa          #+#    #+#              #
#    Updated: 2023/03/06 22:05:52 by jisulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Werror -Wextra -Wall
READL = -L${HOME}/.brew/opt/readline/lib
READI = -I${HOME}/.brew/opt/readline/include
# READL = -lreadline $(LDFLAGS)
# READI =$(CPPFLAGS)

SRC = test_funcs.c \
		minishell.c \
		parse_argv.c \
		parse_env.c \
		parse_token.c \
		free.c \
		make_envp_list.c \
		set_signal.c \
		signal.c \
		pipex.c \
		error_control.c \
		echo.c \
		pwd.c \
		env.c \
		export.c \
		unset.c \
		exit.c \
		cd.c \


SRCS = $(addprefix ./srcs/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(READI) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -lreadline $(READL) $(READI) $^ -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

.PHONY : all clean fclean re
