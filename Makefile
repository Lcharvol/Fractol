# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 16:21:10 by lcharvol          #+#    #+#              #
#    Updated: 2017/02/28 16:21:11 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS := srcs/main.c 
SRCS += srcs/ft_julia.c
SRCS += srcs/ft_mandelbrot.c
SRCS += srcs/tools.c
SRCS += srcs/hooks.c

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -Lmlx/ -lmlx -framework OpenGL -framework AppKit libft/libft.a
	echo "Fractol done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
