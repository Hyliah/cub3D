/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_ray_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:09 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the ray direction for the current screen column.
 *
 * Combines the player's view direction with the camera plane and cam_x
 * to obtain the exact ray direction.
 *
 * @param cub Main game structure.
 */
void	cal_ray_dir(t_cub *cub)
{
	cub->player.ray_dir_x
		= cub->player.dir_x + cub->player.pl_x * cub->player.cam_x;
	cub->player.ray_dir_y
		= cub->player.dir_y + cub->player.pl_y * cub->player.cam_x;
}
