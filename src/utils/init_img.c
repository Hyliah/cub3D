/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:54:42 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:56:41 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_t_img(t_img *img);

/**
 * @brief initalise all the t_img structures.
 * 
 * @param cub Main game structure.
 */
void	init_t_imgs(t_cub *cub)
{
	init_t_img(&cub->weapons.img_w1);
	init_t_img(&cub->weapons.img_w2);
	init_t_img(&cub->weapons.img_w3);
	init_t_img(&cub->weapons.img_w4);
	init_t_img(&cub->weapons.img_w5);
	init_t_img(&cub->oscreen.img_olay);
	init_t_img(&cub->graphic.img_screen);
	init_t_img(&cub->graphic.img_e);
	init_t_img(&cub->graphic.img_s);
	init_t_img(&cub->graphic.img_w);
	init_t_img(&cub->graphic.img_n);
	init_t_img(&cub->graphic.img_door);
	init_t_img(&cub->mmap.img_mmap);
	init_t_img(&cub->mmap.img_player);
	cub->key.k_a = FALSE;
	cub->key.k_s = FALSE;
	cub->key.k_d = FALSE;
	cub->key.k_w = FALSE;
	cub->key.k_up = FALSE;
	cub->key.k_do = FALSE;
	cub->key.k_le = FALSE;
	cub->key.k_ri = FALSE;
	cub->key.k_sh = FALSE;
}

/**
 * @brief initilise a single structure t_img.
 * 
 * @param img structure t_img to be initialized.
 */
static void	init_t_img(t_img *img)
{
	img->addr_ptr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->img_ptr = NULL;
	img->size_line = 0;
}
