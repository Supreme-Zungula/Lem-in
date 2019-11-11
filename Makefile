# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzungula <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 11:31:48 by yzungula          #+#    #+#              #
#    Updated: 2018/10/15 11:31:51 by yzungula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	lemin
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
LIBFT = ./libft/libft.a
HEADER = ./inc/lemin.h
SRC = ./src/links.c \
	  ./src/read_data.c \
	  ./src/error.c \
	  ./src/file.c \
	  ./src/rooms.c \
	  ./src/path.c \
	  ./src/main.c

OBJ = $(SRC:.c=.o)

$(NAME): $(HEADER) $(SRC)
	@make -C $(LIBFTDIR)
	gcc $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re