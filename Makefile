NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = ft_printf.c \
			ft_functions.c \

all: $(NAME)

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re