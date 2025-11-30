/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:58:57 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:01:52 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_after_game(t_cub *cub);
static void	safe_destroy_display(void **mlx_ptr);
static void	safe_destroy_window(void *mlx_ptr, void **win_ptr);

/**
 * @brief Cleans all allocated resources and exits the program safely.
 *
 * Frees textures, images, the minimap, the display, and the MLX window.
 * If the game is running, also frees weapon and overlay resources.
 * Finally exits the program with EXIT_SUCCESS.
 *
 * @param cub Main game structure. If NULL, nothing is freed.
 * @return int Always returns 1 if cub is NULL, otherwise does not return.
 */
int	clean_exit(t_cub *cub)
{
	if (!cub)
		return (1);
	if (cub->game_on == TRUE)
		free_after_game(cub);
	free_t_img(cub, &cub->mmap.img_mmap);
	free_t_img(cub, &cub->mmap.img_player);
	free_t_img(cub, &cub->graphic.img_n);
	free_t_img(cub, &cub->graphic.img_s);
	free_t_img(cub, &cub->graphic.img_w);
	free_t_img(cub, &cub->graphic.img_e);
	free_t_img(cub, &cub->graphic.img_door);
	free_t_img(cub, &cub->graphic.img_screen);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_os);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_pe);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_si);
	free_tab(&cub->map.map_tab);
	free_textures(cub);
	safe_destroy_window(cub->graphic.mlx_ptr, (void **)&cub->graphic.win_ptr);
	safe_destroy_display((void **)&cub->graphic.mlx_ptr);
	free_ptr(&cub->graphic.mlx_ptr);
	exit (EXIT_SUCCESS);
}

/**
 * @brief Frees all texture path strings stored in settings.
 *
 * Frees NO, SO, WE, EA texture file paths.
 *
 * @param cub Main game structure.
 */
void	free_textures(t_cub *cub)
{
	free_ptr((void **)&cub->setting.tex_no);
	free_ptr((void **)&cub->setting.tex_so);
	free_ptr((void **)&cub->setting.tex_we);
	free_ptr((void **)&cub->setting.tex_ea);
}

/**
 * @brief Safely destroys an MLX window and sets the pointer to NULL.
 *
 * @param mlx_ptr MLX instance pointer.
 * @param win_ptr Address of the window pointer.
 */
static void	safe_destroy_window(void *mlx_ptr, void **win_ptr)
{
	if (mlx_ptr && *win_ptr)
	{
		mlx_destroy_window(mlx_ptr, *win_ptr);
		*win_ptr = NULL;
	}
}

/**
 * @brief Safely destroys the MLX display and frees the MLX instance.
 *
 * Sets the mlx_ptr to NULL after freeing.
 *
 * @param mlx_ptr Address of the MLX pointer.
 */
static void	safe_destroy_display(void **mlx_ptr)
{
	if (*mlx_ptr)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		*mlx_ptr = NULL;
	}
}

/**
 * @brief Frees resources that are allocated only after the game starts.
 *
 * This includes:
 *  - weapon animation frames
 *  - weapon overlay (olay)
 *
 * @param cub Main game structure.
 */
static void	free_after_game(t_cub *cub)
{
	free_t_img(cub, &cub->weapons.img_w1);
	free_t_img(cub, &cub->weapons.img_w2);
	free_t_img(cub, &cub->weapons.img_w3);
	free_t_img(cub, &cub->weapons.img_w4);
	free_t_img(cub, &cub->weapons.img_w5);
	free_t_img(cub, &cub->oscreen.img_olay);
}
