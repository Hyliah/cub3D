/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_camera_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:37 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:47 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the camera-space X coordinate for the current screen column.
 *
 * Converts the screen column index into a normalized value between -1 and 1.
 * This value is later used to compute the direction of the ray.
 *
 * @param cub Main game structure.
 * @param x   Horizontal pixel column index.
 */
void	cal_camera_x(t_cub *cub, int x)
{
	cub->player.cam_x = 2.0f * x / (float)cub->graphic.s_width - 1.0f;
}
