# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snaji <snaji@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:21:26 by wmari             #+#    #+#              #
#    Updated: 2023/08/24 14:36:01 by snaji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
MLX 	= minilibx-linux

INCLUDE	= -I includes -I libft/headers -I $(MLX)
INCL_B	= -I includes_bonus -I libft/headers -I $(MLX)

LIB		= -L libft -L $(MLX) -lft -lmlx_Linux -lm -lXext -lX11 -lz

SRCS	= srcs/main.c\
		srcs/mlx_hooks.c\
		srcs/parsing/parsing_map.c\
		srcs/parsing/errors.c\
		srcs/parsing/parsing_el.c\
		srcs/parsing/parsing.c\
		srcs/parsing/verif_map.c\
		srcs/parsing/utils.c\
		srcs/raycast.c\
		srcs/raycast2.c\
		srcs/image_utils.c\
		srcs/utils.c\
		srcs/init_world.c\
		srcs/mlx_hook_utils.c\
		srcs/collision.c\
		srcs/movement.c\
		srcs/collision_utils.c

SRCS_B	= srcs_bonus/main.c\
		srcs_bonus/mlx_hooks.c\
		srcs_bonus/parsing/parsing_map.c\
		srcs_bonus/parsing/errors.c\
		srcs_bonus/parsing/parsing_el.c\
		srcs_bonus/parsing/parsing.c\
		srcs_bonus/parsing/verif_map.c\
		srcs_bonus/parsing/utils.c\
		srcs_bonus/raycast.c\
		srcs_bonus/raycast2.c\
		srcs_bonus/image_utils.c\
		srcs_bonus/utils.c\
		srcs_bonus/init_world.c\
		srcs_bonus/mlx_hook_utils.c\
		srcs_bonus/minimap.c\
		srcs_bonus/collision.c\
		srcs_bonus/movement.c\
		srcs_bonus/tracking_mouse.c\
		srcs_bonus/texture.c\
		srcs_bonus/open_anim.c\
		srcs_bonus/collision_utils.c
		
OBJS	= $(patsubst srcs/%.c, bin/%.o, $(SRCS))
OBJS_B	= $(patsubst srcs_bonus/%.c, bin_bon/%.o, $(SRCS_B))
DEPS	= includes/cub3D.h includes/raycast.h
DEPS_B	= includes_bonus/cub3D.h includes_bonus/raycast.h
NAME	= cub3D
NAME_B	= cub3D_bonus

all: $(NAME)

objsdir:
	@mkdir -p bin

objs_bdir:
	@mkdir -p bin_bon

bin/%.o: srcs/%.c $(DEPS) | objsdir
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCLUDE) -o $@ $<

bin_bon/%.o: srcs_bonus/%.c $(DEPS_B) | objs_bdir
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(INCL_B) -o $@ $<

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $(LIB)

$(NAME_B): $(OBJS_B)
	make -C $(MLX)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B) $(INCL_B) $(LIB)

bonus: $(NAME_B)
	
clean:
	make -C libft clean
	make -C $(MLX) clean
	rm -rf bin
	rm -rf bin_bon

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) $(NAME_B)

re: fclean
	make all

.PHONY: all clean fclean re