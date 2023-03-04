# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:36:43 by junhyupa          #+#    #+#              #
#    Updated: 2023/03/04 16:52:39 by junhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Werror -Wextra -Wall -g -fsanitize=address
READL = -L${HOME}/.brew/opt/readline/lib
READI = -I${HOME}/.brew/opt/readline/include
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
