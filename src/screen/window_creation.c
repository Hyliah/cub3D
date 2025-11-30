/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:18:55 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:15:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	game_on(t_cub *cub);
static void	mm_size_calculator(t_cub *cub);
static int	init_img(t_cub *cub, t_img *img, t_bool minimap);

/**
 * @brief Initializes the MLX window and all game-related images.
 *
 * Creates the MLX instance, opens the game window, computes minimap size,
 * loads opening screen assets, wall textures and allocates all required images
 * (screen buffer, minimap, player icon). Finally starts the main game loop.
 *
 * @param cub Main game structure.
 * @return 0 on success, 1 on failure.
 */
int	create_window(t_cub *cub)
{
	cub->graphic.mlx_ptr = mlx_init();
	if (!cub->graphic.mlx_ptr)
		return (clean_exit(cub), 1);
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr,
			cub->graphic.s_width, cub->graphic.s_height, G_NAME);
	if (!cub->graphic.win_ptr)
		return (clean_exit(cub), 1);
	mm_size_calculator(cub);
	if (init_opening_screen(cub))
		return (1);
	if (init_walls(cub))
		return (1);
	if (init_img(cub, &cub->graphic.img_screen, FALSE))
		return (1);
	if (init_img(cub, &cub->mmap.img_mmap, TRUE))
		return (1);
	if (init_img(cub, &cub->mmap.img_player, TRUE))
		return (1);
	game_on(cub);
	return (0);
}

/**
 * @brief Initializes an MLX image buffer.
 *
 * Creates a new image with either:
 *  - Screen resolution (if minimap == FALSE)
 *  - Minimap resolution (if minimap == TRUE)
 *
 * Also retrieves the data address, bpp, line size, and endian.
 *
 * @param cub      Main game structure.
 * @param img      Pointer to the image structure to initialize.
 * @param minimap  TRUE to init a minimap-sized image, FALSE for full screen.
 * @return 0 on success, 1 on failure.
 */
static int	init_img(t_cub *cub, t_img *img, t_bool minimap)
{
	int	x;
	int	y;

	if (minimap)
	{
		x = cub->mmap.mm_wid;
		y = cub->mmap.mm_hei;
	}
	else
	{
		x = cub->graphic.s_width;
		y = cub->graphic.s_height;
	}
	img->img_ptr = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	if (!img->img_ptr)
		return (clean_exit(cub), 1);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
	return (0);
}

/**
 * @brief Computes the minimap dimensions and square size.
 *
 * Determines the minimap's width and height based on the map ratio
 * (map width / map height) so that it fits within MAX_W/H limits.
 *
 * Also computes the pixel size of one map cell on the minimap (mm_sqr).
 *
 * @param cub Main game structure.
 */
static void	mm_size_calculator(t_cub *cub)
{
	int	mm_ratio;

	mm_ratio = cub->map.width / cub->map.height;
	if (mm_ratio > 1)
	{
		cub->mmap.mm_wid = MM_MAX_W;
		cub->mmap.mm_hei = MM_MAX_W / mm_ratio;
	}
	else
	{
		cub->mmap.mm_hei = MM_MAX_H;
		cub->mmap.mm_wid = MM_MAX_H * mm_ratio;
	}
	cub->mmap.mm_sqr = cub->mmap.mm_wid / cub->map.width;
}

/**
 * @brief Starts the main game loop.
 *
 * Creates the minimap, then enters the raycasting loop as long
 * as the game state is active. Also registers window close event.
 *
 * @param cub Main game structure.
 */
static void	game_on(t_cub *cub)
{
	mm_creation(cub);
	while (cub->game_on == TRUE)
		raycasting(cub);
	mlx_hook(cub->graphic.win_ptr, 17, 0, clean_exit, cub);
}
