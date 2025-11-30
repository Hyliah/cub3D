/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:08:37 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:13:09 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_img	*choose_wall(t_cub *cub, int side);
static void		fill_pixels(t_cub *cub, t_img *tex, int x);

/**
 * @brief Computes texture coordinates and draws one vertical wall slice.
 *
 * Determines the exact texture column to use, computes drawing limits,
 * and triggers pixel rendering for the current column.
 *
 * @param cub Main game structure.
 * @param x   Current screen column.
 * @param side 0 = vertical wall, 1 = horizontal wall.
 */
void	texture_cal(t_cub *cub, int x, int side)
{
	t_img	*tex;

	tex = choose_wall(cub, side);
	if (side == 0)
		cub->tex.wall_x = cub->player.pos_y
			+ cub->player.perp_wall_dist * cub->player.ray_dir_y;
	else
		cub->tex.wall_x = cub->player.pos_x
			+ cub->player.perp_wall_dist * cub->player.ray_dir_x;
	cub->tex.wall_x -= floor(cub->tex.wall_x);
	cub->tex.tex_x = (int)(cub->tex.wall_x * (float)tex->width);
	if ((side == 0 && cub->player.ray_dir_x > 0)
		|| (side == 1 && cub->player.ray_dir_y < 0))
		cub->tex.tex_x = tex->width - cub->tex.tex_x - 1;
	cub->tex.step = 1.0f * tex->height / cub->player.line_height;
	cub->tex.draw_start = cal_range(cub, TRUE);
	cub->tex.draw_end = cal_range(cub, FALSE);
	cub->tex.tex_pos = (cub->tex.draw_start - cub->graphic.s_height / 2
			+ cub->player.line_height / 2) * cub->tex.step;
	fill_pixels(cub, tex, x);
}

/**
 * @brief Fills the screen column with ceiling, wall texture, and floor colors.
 *
 * Draws three vertical segments:
 *  - Ceiling: from y = 0 to draw_start
 *  - Wall: sampled from the selected texture between draw_start and draw_end
 *  - Floor: from draw_end to the bottom of the screen
 *
 * Texture sampling uses tex_pos and tex_y 
 * to step vertically through the texture.
 *
 * @param cub Main game structure.
 * @param tex Pointer to the texture image for the wall slice.
 * @param x   Current screen column index.
 */
static void	fill_pixels(t_cub *cub, t_img *tex, int x)
{
	int		y;
	t_hex_c	color;

	y = 0;
	while (y < cub->tex.draw_start)
	{
		set_pixel(&cub->graphic.img_screen, x, y, cub->setting.c_color);
		y++;
	}
	while (y < cub->tex.draw_end)
	{
		cub->tex.tex_y = (int)cub->tex.tex_pos & (tex->height - 1);
		cub->tex.tex_pos += cub->tex.step;
		color = get_pixel(tex, cub->tex.tex_x, cub->tex.tex_y);
		set_pixel(&cub->graphic.img_screen, x, y, color);
		y++;
	}
	while (y < cub->graphic.s_height)
	{
		set_pixel(&cub->graphic.img_screen, x, y, cub->setting.f_color);
		y++;
	}
}

/**
 * @brief Selects the correct wall texture based on the ray dir and hit side.
 *
 * Chooses texture depending on:
 *  - Whether the hit object is a door.
 *  - Side of impact: vertical (side = 0) or horizontal (side = 1).
 *  - Ray direction (east/west or north/south).
 *
 * @param cub  Main game structure.
 * @param side 0 for vertical wall hit, 1 for horizontal.
 * @return Pointer to the corresponding texture image.
 */
static t_img	*choose_wall(t_cub *cub, int side)
{
	if (cub->player.is_door == FALSE)
	{
		if (side == 0)
		{
			if (cub->player.ray_dir_x > 0)
				return (&cub->graphic.img_e);
			else
				return (&cub->graphic.img_w);
		}
		else
		{
			if (cub->player.ray_dir_y > 0)
				return (&cub->graphic.img_s);
			else
				return (&cub->graphic.img_n);
		}
	}
	else
		return (&cub->graphic.img_door);
}
