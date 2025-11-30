/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_side_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:05 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:06 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the initial side distances for the DDA algorithm.
 *
 * Determines how far the ray must travel in X or Y before hitting
 * the first grid boundary.
 *
 * @param cub Main game structure.
 */
void	cal_side_dist(t_cub *cub)
{
	if (cub->player.ray_dir_x < 0)
		cub->player.side_dist_x
			= ((cub->player.pos_x - (float)cub->player.map_x)
				* cub->player.delta_dist_x);
	else
		cub->player.side_dist_x
			= ((cub->player.map_x + 1.0 - cub->player.pos_x)
				* cub->player.delta_dist_x);
	if (cub->player.ray_dir_y < 0)
		cub->player.side_dist_y
			= ((cub->player.pos_y - (float)cub->player.map_y)
				* cub->player.delta_dist_y);
	else
		cub->player.side_dist_y
			= ((cub->player.map_y + 1.0 - cub->player.pos_y)
				* cub->player.delta_dist_y);
}
