NAME := libft.a

CC := cc
CFLAGS:= -Wall -Wextra -Werror

RM := rm -f

AR := ar
ARFLAGS := rcs

INCLUDES := ./libft.h

SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strrchr.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS_BN := ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS := $(SRCS:.c=.o)
OBJS_BN := $(SRCS_BN:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BN)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(if $(filter bonus, $(MAKECMDGOALS)), $(BNS_OBJS))
	$(AR) $(ARFLAGS) $@ $^

bonus : $(NAME)

.PHONY : all clean fclean re
