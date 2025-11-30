/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_delta_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:29 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:30 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the delta distances used for the DDA algorithm.
 *
 * Delta distances represent how far the ray must travel along X or Y
 * to move from one map cell to the next. They are based on the inverse
 * of the ray direction components.
 * 
 * 1e30f is used to secure the 0.0f
 *
 * @param cub Main game structure.
 */
void	cal_delta_dist(t_cub *cub)
{
	if (cub->player.ray_dir_x == 0.0f)
		cub->player.delta_dist_x = 1e30f;
	else
		cub->player.delta_dist_x = fabsf(1.0f / cub->player.ray_dir_x);
	if (cub->player.ray_dir_y == 0.0f)
		cub->player.delta_dist_y = 1e30f;
	else
		cub->player.delta_dist_y = fabsf(1.0f / cub->player.ray_dir_y);
}
