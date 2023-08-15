/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:51:36 by wmari             #+#    #+#             */
/*   Updated: 2023/08/15 17:33:04 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keyrelease(int keycode, t_world *world)
{
	if (keycode == W)
		world->keys.up = 0;
	if (keycode == S)
		world->keys.down = 0;
	if (keycode == A)
		world->keys.left = 0;
	if (keycode == D)
		world->keys.right = 0;
	if (keycode == L_ARROW)
		world->keys.larrow = 0;
	if (keycode == R_ARROW)
		world->keys.rarrow = 0;
	if (keycode == ESCAPE)
		world->keys.escape = 0;
	if (keycode == E)
		world->keys.use = 0;
	return (hook_key_press(world));
}

int	keypresses(int keycode, t_world *world)
{
	if (keycode == W)
		world->keys.up = 1;
	if (keycode == S)
		world->keys.down = 1;
	if (keycode == A)
		world->keys.left = 1;
	if (keycode == D)
		world->keys.right = 1;
	if (keycode == L_ARROW)
		world->keys.larrow = 1;
	if (keycode == R_ARROW)
		world->keys.rarrow = 1;
	if (keycode == ESCAPE)
		world->keys.escape = 1;
	if (keycode == E)
	{
		door_use(world);
		world->keys.use = 1;
	}
	return (hook_key_press(world));
}

int	keys_is_not_pressed(t_world *world)
{
	if (world->keys.escape || world->keys.up || world->keys.down
		|| world->keys.left || world->keys.right || world->keys.larrow
		|| world->keys.rarrow || world->keys.use)
		return (0);
	return (1);
}

void	door_use(t_world *world)
{
	const int	mapx = (int)(world->pos.x + world->dir.x);
	const int	mapy = (int)(world->pos.y + world->dir.y);
	const int	ne[][2] = {{mapx + 1, mapy}, {mapx, mapy + 1}, {mapx - 1, mapy},
	{mapx, mapy - 1}};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ne[i][0] < 0 || ne[i][1] < 0 || world->map[ne[i][1]] == NULL
			|| world->map[ne[i][1]][ne[i][0]] == '\0'
			|| world->map[ne[i][1]][ne[i][0]] == ' ')
			return ;
		++i;
	}
	if (world->map[mapy][mapx] == '2')
		world->map[mapy][mapx] = '3';
	else if (world->map[mapy][mapx] == '3')
		world->map[mapy][mapx] = '2';
}
