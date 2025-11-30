/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:16:52 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:16:54 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Updates the player direction vector and camera plane based on angle.
 *
 * Converts the player's angle into directional vectors used for raycasting.
 *
 * @param cub Main game structure.
 */
void	cal_view(t_cub *cub)
{
	float	angle;
	float	fov;

	angle = cub->player.angle * M_PI / 180.0;
	fov = 0.66;
	cub->player.dir_x = cos(angle);
	cub->player.dir_y = -sin(angle);
	cub->player.pl_x = sin(angle) * fov;
	cub->player.pl_y = cos(angle) * fov;
}
