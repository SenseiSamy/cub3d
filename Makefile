# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaji <snaji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:21:26 by wmari             #+#    #+#              #
#    Updated: 2023/06/24 14:16:27 by snaji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MLX 	= minilibx-linux

INCLUDE	= -I includes -I libft/headers -I $(MLX)
LIB		= -L libft -L $(MLX) -lft -lmlx_Linux -lm
SRCS	= srcs/test/main.c
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
	rm -rf bin

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re