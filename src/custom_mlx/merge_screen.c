/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:09:42 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:14:01 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y);

/**
 * @brief Composes the final screen by merging layers and drawing to the window
 *
 * This function handles:
 *  - Raycasting rendering
 *  - Minimap display (if enabled)
 *  - Weapon animation overlay
 *  - Screen overlay
 *
 * @param cub Pointer to the main game structure.
 */
void	merge_screens(t_cub *cub)
{
	int	mmap_x;
	int	mmap_y;

	if (cub->game_on == TRUE)
		raycasting(cub);
	if (cub->mmap.mm_show == TRUE)
	{
		mmap_x = cub->graphic.s_width - cub->mmap.mm_wid - 20;
		mmap_y = 20;
		merge_screen(cub, &cub->mmap.img_mmap, mmap_x, mmap_y);
		merge_screen(cub, &cub->mmap.img_player, mmap_x, mmap_y);
	}
	merge_screen(cub, move_weapon(cub), 0, 0);
	merge_screen(cub, &cub->oscreen.img_olay, 0, 0);
	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
		cub->graphic.img_screen.img_ptr, 0, 0);
}

/**
 * @brief Merges a source image onto the main screen with an offset.
 *
 * Non-black pixels (0x000000) are drawn on top of the screen image.
 *
 * @param cub Pointer to the main game structure.
 * @param img Source image to merge.
 * @param offset_x Horizontal offset on the screen.
 * @param offset_y Vertical offset on the screen.
 */
static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y)
{
	int		x;
	int		y;
	t_hex_c	pixel_color;

	y = 0;
	while (y < img->height && (y + offset_y) < cub->graphic.s_height)
	{
		x = 0;
		while (x < img->width && (x + offset_x) < cub->graphic.s_width)
		{
			pixel_color = get_pixel(img, x, y);
			if (pixel_color != 0x000000)
				set_pixel(&cub->graphic.img_screen, x + offset_x, y + offset_y,
					pixel_color);
			x++;
		}
		y++;
	}
}
