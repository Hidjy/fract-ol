# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laime <laime@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 16:56:15 by laime             #+#    #+#              #
#    Updated: 2015/01/04 19:46:07 by laime            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fractol.c fractal.c hook.c g.c
HEADERS = fractol.h
OBJ = $(SRC:.c=.o)
OPT = -Wall -Werror -Wextra
LIBS = -lm -L /usr/X11/lib -lmlx -lXext -lX11 -L libft -lft

all: $(NAME)

.PHONY: libft clean fclean re

$(NAME): libft
	gcc $(OPT) -c $(SRC) -I /opt/X11/include/
	gcc -o $(NAME) $(OBJ) $(LIBS)

libft:
	make -C libft fclean
	make -C libft

clean:
	/bin/rm -f $(OBJ) $(HEADERS:.h=.h.gch)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
