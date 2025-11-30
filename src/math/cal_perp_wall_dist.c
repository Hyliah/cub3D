/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_perp_wall_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:16 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the perpendicular distance from the player to the wall hit.
 *
 * Chooses the correct distance depending on whether the ray hit
 * a vertical (side = 0) or horizontal (side = 1) wall.
 *
 * @param cub  Main game structure.
 * @param side 0 if a vertical wall was hit, 1 otherwise.
 */
void	cal_perp_wall_dist(t_cub *cub, int side)
{
	if (side == 0)
		cub->player.perp_wall_dist
			= cub->player.side_dist_x - cub->player.delta_dist_x;
	else
		cub->player.perp_wall_dist
			= cub->player.side_dist_y - cub->player.delta_dist_y;
}
