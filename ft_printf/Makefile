NAME = libftprintf.a
LIBFT = libft/libft.a
SRCS = ft_printf.c \
		ft_printf_utils.c \
		print_char.c \
		print_str.c \
		print_nbr.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcu
RM = rm -f
MV = mv

$(NAME) : $(OBJS)
		$(MAKE) bonus -C ./libft
		$(MV) $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean : clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re