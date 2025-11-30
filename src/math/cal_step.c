/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:00 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:02 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the step direction (step_x, step_y) for the DDA algorithm.
 *
 * Indicates whether the ray moves left/right or up/down depending
 * on its direction.
 *
 * @param cub Main game structure.
 */
void	cal_step(t_cub *cub)
{
	if (cub->player.ray_dir_x < 0)
		cub->player.step_x = -1;
	else
		cub->player.step_x = 1;
	if (cub->player.ray_dir_y < 0)
		cub->player.step_y = -1;
	else
		cub->player.step_y = 1;
}
