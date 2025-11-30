/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:54:21 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:54:36 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	mm_drawing(t_cub *cub);
static void	mm_draw_mm_sqr(t_cub *cub, int color, int x, int y);

/**
 * @brief handle the creation of the minimap and the player
 * 
 * @param cub Main game structure.
 */
void	mm_creation(t_cub *cub)
{
	mm_drawing(cub);
	mm_player_draw(cub, 0x622416);
}

/**
 * @brief Renders pixels to create a minimap with floors, walls and doors.
 * 
 * @param cub Main game structure.
 */
static void	mm_drawing(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < cub->map.height)
	{
		y = 0;
		while (y < cub->map.width
			&& cub->map.map_tab[x][y])
		{
			if (cub->map.map_tab[x][y] == '1')
				mm_draw_mm_sqr(cub, 0x4B6E49, x, y);
			if (cub->map.map_tab[x][y] == 'D')
				mm_draw_mm_sqr(cub, 0x499E49, x, y);
			else if (cub->map.map_tab[x][y] == '0'
				|| cub->map.map_tab[x][y] == 'N'
				|| cub->map.map_tab[x][y] == 'S'
				|| cub->map.map_tab[x][y] == 'E'
				|| cub->map.map_tab[x][y] == 'W')
				mm_draw_mm_sqr(cub, 0xC7CB9F, x, y);
			y++;
		}
		x++;
	}
}

/**
 * @brief Renders a square of the minimp with a matching color
 * 
 * @param cub Main game structure.
 * @param color Color of the diamond
 * @param x Map grid coordinate x
 * @param y Map grid coordinate y
 */
static void	mm_draw_mm_sqr(t_cub *cub, int color, int x, int y)
{
	int	px;
	int	py;
	int	sqr;

	py = 0;
	sqr = cub->mmap.mm_sqr;
	while (py < sqr)
	{
		px = 0;
		while (px < sqr)
		{
			set_pixel(&cub->mmap.img_mmap,
				(y * sqr + py), (x * sqr + px), color);
			px++;
		}
		py++;
	}
}
