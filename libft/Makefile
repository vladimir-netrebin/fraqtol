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

NAME = libft.a

CC = gcc

SOURCES = ft_cntwords.c ft_atoi.c ft_bzero.c ft_capitalize.c ft_check.c ft_in.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_loweraze.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c get_next_line.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\e[38;5;87mBuilding $<\e[0m\n"

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\e[38;5;255m$(NAME) Build complete!\e[0m\n"

clean:
	@/bin/rm -f $(OBJECTS)
	@printf "\e[38;5;9mClean!\e[0m\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\e[38;5;226mFully clean!\e[0m\n"

re: fclean all
