/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:08:58 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:16:48 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_doors_hit(t_cub *cub, int *hit);

/**
 * @brief Performs the DDA (Digital Differential Analyzer) grid traversal.
 *
 * Advances step by step through the map grid until a wall or door is hit.
 * Also returns which side of the wall was hit.
 *
 * @param cub Main game structure.
 * @return 0 if a vertical wall was hit, 1 if horizontal.
 */
int	dda(t_cub *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->player.side_dist_x < cub->player.side_dist_y)
		{
			cub->player.side_dist_x += cub->player.delta_dist_x;
			cub->player.map_x += cub->player.step_x;
			side = 0;
		}
		else
		{
			cub->player.side_dist_y += cub->player.delta_dist_y;
			cub->player.map_y += cub->player.step_y;
			side = 1;
		}
		check_doors_hit(cub, &hit);
	}
	return (side);
}

/**
 * @brief Checks if the ray has hit a wall or a closed door.
 *
 * Sets the player's door-hit state and updates the DDA hit flag if:
 *  - The map cell contains a wall ('1'), or
 *  - The cell contains a closed door ('D' and is_door_open == FALSE)
 *
 * @param cub Main game structure.
 * @param hit Pointer to the DDA hit flag (set to 1 when a solid object is hit).
 */
static void	check_doors_hit(t_cub *cub, int *hit)
{
	if (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == 'D'
			&& cub->map.is_door_open == FALSE)
		cub->player.is_door = TRUE;
	else
		cub->player.is_door = FALSE;
	if (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == '1'
		|| (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == 'D'
		&& cub->map.is_door_open == FALSE))
		*hit = 1;
}
