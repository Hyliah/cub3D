/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:28:23 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:31:05 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Initializes all opening screen images and displays the main one.
 *
 * @param cub Main game structure.
 * @return int 0 on success, 1 on failure.
 */
int	init_opening_screen(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	cub->oscreen.img_os
		= mlx_xpm_file_to_image(cub->graphic.mlx_ptr, OS, &x, &y);
	if (!cub->oscreen.img_os)
		return (clean_exit(cub), 1);
	cub->oscreen.img_pe
		= mlx_xpm_file_to_image(cub->graphic.mlx_ptr, OSP, &x, &y);
	if (!cub->oscreen.img_pe)
		return (clean_exit(cub), 1);
	cub->oscreen.img_si
		= mlx_xpm_file_to_image(cub->graphic.mlx_ptr, OSS, &x, &y);
	if (!cub->oscreen.img_si)
		return (clean_exit(cub), 1);
	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
		cub->oscreen.img_os, 0, 0);
	return (0);
}

/**
 * @brief Handles keyboard input for navigating the opening screen.
 *
 * - ENTER starts the game and loads overlays.
 * - UP chooses Sirius. (default one)
 * - DOWN chooses Pepito.
 *
 * @param cub Main game structure.
 * @param keycode Pressed key.
 * @return int 0 on success, 1 on failure.
 */
int	opening_screen_handle(t_cub *cub, int keycode)
{
	if (keycode == KEY_RETURN)
	{
		cub->game_on = TRUE;
		if (init_overlays_weapons(cub))
			return (1);
	}
	else if (cub->key.k_up && cub->game_on == FALSE)
	{
		cub->oscreen.is_sirius = TRUE;
		mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
			cub->oscreen.img_si, 0, 0);
	}
	else if (cub->key.k_do && cub->game_on == FALSE)
	{
		cub->oscreen.is_sirius = FALSE;
		mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
			cub->oscreen.img_pe, 0, 0);
	}
	return (0);
}
