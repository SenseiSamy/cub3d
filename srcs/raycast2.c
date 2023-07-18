/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:11:14 by snaji             #+#    #+#             */
/*   Updated: 2023/07/18 18:16:43 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static t_image	*get_wall_text(t_raycast *r, t_world *world, char wall)
{
	double	angle;

	angle = atan2(r->raydir.y, r->raydir.x) * 180 / M_PI + 180;
	if (wall == '2')
		return (&world->door);
	if (r->side == 1)
	{
		if (angle < 180.0)
			return (&world->southwall);
		return (&world->northwall);
	}
	else
	{
		if (angle >= 90.0 && angle <= 270.0)
			return (&world->westwall);
		return (&world->eastwall);
	}
}