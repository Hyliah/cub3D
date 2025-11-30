/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:19 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:17:21 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Updates the player's map grid coordinates (map_x, map_y).
 *
 * Converts the player's float position to integer map indices.
 *
 * @param cub Main game structure.
 */
void	cal_map(t_cub *cub)
{
	cub->player.map_x = (int)cub->player.pos_x;
	cub->player.map_y = (int)cub->player.pos_y;
}
