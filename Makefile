# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 14:44:38 by cmanfred          #+#    #+#              #
#    Updated: 2019/02/27 14:44:30 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror -I includes/ -g
LIBFLAGS = -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -lpthread
FILES = main.c mapread.c ft_cut_off.c image_operations.c init.c linedraw.c vector_operations.c hook_mouse.c
INCFILES = includes/fdf.h
SRCS = $(addprefix srcs/, $(FILES))
OBJ = $(addprefix objectives/, $(FILES:.c=.o))

all: $(NAME)

$(NAME):$(OBJ) $(INCFILES) | lib
	@gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ)

objectives/%.o: srcs/%.c | objectives
	@gcc $(FLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make -C ./minilibx

clean:
	@rm -rf objectives/
	@make clean -C ./libft
	@make clean -C ./minilibx

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

objectives:
	@mkdir objectives/
