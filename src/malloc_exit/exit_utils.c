/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:02:44 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:13:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Cleans parsing-related resources and exits the program with failure.
 *
 * This function is used when an error occurs during map or settings parsing.
 * It safely frees:
 *  - the currently read line
 *  - texture paths
 *  - the map structure
 *  - the parsing file descriptor
 *
 * After cleanup, the function terminates the program with EXIT_FAILURE.
 *
 * @param cub Pointer to the main game structure. If NULL, exits immediately.
 * @return int Never returns; the program terminates.
 */
int	clean_exit_parsing(t_cub *cub)
{
	if (cub->map.current_line)
	{
		free(cub->map.current_line);
		cub->map.current_line = NULL;
	}
	if (!cub)
		exit(EXIT_FAILURE);
	if (cub->setting.fd > 2)
	{
		close(cub->setting.fd);
		cub->setting.fd = -1;
	}
	free_textures(cub);
	free_map(cub);
	cub->map.map_start = 0;
	exit(EXIT_FAILURE);
}

/**
 * @brief Frees a t_img structure and destroys its MLX image if it exists.
 *
 * Calls safe_destroy_image() and then nullifies the internal data pointer.
 *
 * @param cub Pointer to the main game structure.
 * @param img Pointer to the image struct to free/reset.
 */
void	free_t_img(t_cub *cub, t_img *img)
{
	if (!cub || !img)
		return ;
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&img->img_ptr);
	img->addr_ptr = NULL;
}

/**
 * @brief Safely destroys an MLX image and sets its pointer to NULL.
 *
 * Ensures that both mlx_ptr and img_ptr are valid 
 * before calling mlx_destroy_image().
 *
 * @param mlx_ptr MLX instance pointer.
 * @param img_ptr Address of the MLX image pointer.
 */
void	safe_destroy_image(void *mlx_ptr, void **img_ptr)
{
	if (mlx_ptr && *img_ptr)
	{
		mlx_destroy_image(mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
}
