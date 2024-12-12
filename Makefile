
SRC = ft_printf.c src/dec.c src/hex.c src/str_n_char.c
OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

re: fclean $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)


.PHONY: fclean clean re all
