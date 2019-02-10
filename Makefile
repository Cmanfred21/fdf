# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 14:44:38 by cmanfred          #+#    #+#              #
#    Updated: 2019/02/10 18:23:34 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -I includes/ -g
LIBFLAGS = -L./libft -lft #-L./minilibx -lmlx -framework OpenGL -framework AppKit
FILES = main.c mapread.c
SRCS = $(addprefix srcs/, $(FILES))
OBJ = $(addprefix objectives/, $(FILES:.c=.o))

all: $(NAME)

$(NAME):$(OBJ) | lib
	gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ)

objectives/%.o: srcs/%.c | objectives
	gcc $(FLAGS) -o $@ -c $^

re: fclean all

lib:
	make -C ./libft
	make -C ./minilibx

clean:
	rm -rf objectives/
	make clean -C ./libft
	make clean -C ./minilibx

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

objectives:
	mkdir objectives/
