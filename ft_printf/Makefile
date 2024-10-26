NAME = libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC =  ft_printf.c ft_printf_utils.c ft_printf_utilhexpoint.c\

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I. -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

test: all
	$(CC) $(CFLAGS) *.o *.a

ct: fclean
	/bin/rm a.out

re: fclean all
