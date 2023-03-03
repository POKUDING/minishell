# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:36:43 by junhyupa          #+#    #+#              #
#    Updated: 2023/03/03 21:27:36 by junhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Werror -Wextra -Wall -g -fsanitize=address
# READL = -lreadline -L/home/linuxbrew/.linuxbrew/Cellar/readline/8.2.1/lib
# READI =-I/home/linuxbrew/.linuxbrew/Cellar/readline/8.2.1/include
# READL = -lreadline $(LDFLAGS)
# READI =$(CPPFLAGS)

SRC = test_funcs.c \
		builtin.c \
		minishell.c \
		parse_argv.c \
		parse_env.c \
		parse_token.c \
		free.c \
		make_envp_list.c \
		set_signal.c \
		signal.c

SRCS = $(addprefix ./srcs/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -l readline -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

.PHONY : all clean fclean re
