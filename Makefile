# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 15:21:33 by ivalenti          #+#    #+#              #
#    Updated: 2020/01/25 15:10:08 by ivalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

SOURCES	=	draw_fraq.c	\
			controls.c	\
			initialize.c \
			julia.c		\
			main.c		\
			mandelbort.c			\
			mouse.c	\
			utiles.c \
			p_mandel.c \
			ship.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

STL = libft/

MLX = minilibx_macos/

all: $(NAME)

$(NAME): $(OBJECTS)
	    make -C $(STL)
		make -C $(MLX)
		$(CC) $(OBJECTS) -I fraq.h -L. $(STL)libft.a -L. $(MLX)libmlx.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	    $(CC) $(CFLAGS) -g -I fraq.h -c $< -o $@

clean:
	    make -C $(STL) clean
		/bin/rm -f $(OBJECTS)
fclean: clean
	    /bin/rm -f $(NAME) $(STL)libft.a
		make -C $(MLX) clean

re: fclean all
