# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaji <snaji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:21:26 by wmari             #+#    #+#              #
#    Updated: 2023/06/25 20:04:30 by snaji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
MLX 	= minilibx-linux

INCLUDE	= -I includes -I libft/headers -I $(MLX)
LIB		= -L libft -L $(MLX) -lft -lmlx_Linux -lm -lXext -lX11 -lz
SRCS	= srcs/main.c\
		srcs/parsing/parsing_map.c\
		srcs/parsing/errors.c\
		srcs/parsing/parsing_el.c\
		srcs/parsing/parsing.c\
		srcs/parsing/verif_map.c\
		srcs/parsing/utils.c
OBJS	= $(patsubst srcs/%.c, bin/%.o, $(SRCS))
NAME	= cub3D

all: $(NAME)

objsdir:
	@mkdir -p bin

bin/%.o: srcs/%.c | objsdir
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCLUDE) -o $@ $^

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	make -C libft clean
	make -C $(MLX) clean
	rm -rf bin

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re