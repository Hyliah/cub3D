/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:08:51 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:08:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Main raycasting loop.
 *
 * For each screen column:
 *  - computes the ray direction,
 *  - performs DDA,
 *  - computes perpendicular distance and wall height,
 *  - selects the correct texture,
 *  - draws the wall slice.
 *
 * @param cub Main game structure.
 */
void	raycasting(t_cub *cub)
{
	int	x;
	int	side;

	x = 0;
	cal_view(cub);
	while (x < cub->graphic.s_width)
	{
		cal_camera_x(cub, x);
		cal_ray_dir(cub);
		cal_map(cub);
		cal_delta_dist(cub);
		cal_step(cub);
		cal_side_dist(cub);
		side = dda(cub);
		cal_perp_wall_dist(cub, side);
		cal_line_height(cub);
		texture_cal(cub, x, side);
		x++;
	}
}
