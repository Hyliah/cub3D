/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_line_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:24 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:25 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Computes the height of the wall slice to be rendered.
 *
 * Uses the perpendicular distance to the wall to determine the projected
 * height of the column on the screen.
 *
 * @param cub Main game structure.
 */
void	cal_line_height(t_cub *cub)
{
	cub->player.line_height
		= (int)(cub->graphic.s_height / cub->player.perp_wall_dist);
}
