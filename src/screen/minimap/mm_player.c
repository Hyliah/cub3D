/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:11:16 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:11:21 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Draws the player on the minimap as a diamond
 * 
 * @param cub Main game structure.
 * @param color Color of the diamond
 */
void	mm_player_draw(t_cub *cub, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	thick;

	x = (int)(cub->player.pos_x * (float)cub->mmap.mm_sqr);
	y = (int)(cub->player.pos_y * (float)cub->mmap.mm_sqr);
	thick = (cub->mmap.mm_sqr - 1) / 2;
	i = -thick;
	while (i <= thick)
	{
		j = -thick;
		while (j <= thick)
		{
			if (abs(i) + abs(j) <= thick)
				set_pixel(&cub->mmap.img_player, (x + i), (y + j), color);
			j++;
		}
		i++;
	}
}
