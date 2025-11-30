/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:26:18 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:26:20 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		change_frame_number(t_cub *cub);
static t_img	*change_frame(t_cub *cub, int actual);

/**
 * @brief Updates the weapon animation frame based on player movement.
 *
 * This function cycles through weapon frames when the player is moving,
 * creating a bobbing animation. It returns the image corresponding to 
 * the current frame.
 *
 * @param cub Main game structure.
 * @return t_img* The current weapon frame image.
 */
t_img	*move_weapon(t_cub *cub)
{
	static int	actual = 1;
	static int	i = 0;

	if (cub->key.k_a || cub->key.k_s || cub->key.k_d || cub->key.k_w)
	{
		if (i == 3)
		{
			i = 0;
			actual = change_frame_number(cub);
		}
		i++;
	}
	return (change_frame(cub, actual));
}

/**
 * @brief Updates the current weapon animation frame index.
 *
 * The animation oscillates between frames 1 and 5. When the highest frame
 * is reached, direction reverses, and vice versa.
 *
 * @param cub Main game structure.
 * @return int The updated frame number.
 */
static int	change_frame_number(t_cub *cub)
{
	int		actual;
	t_bool	is_up;

	actual = cub->weapons.s_nb;
	is_up = cub->weapons.up;
	if (actual < 5 && is_up == TRUE)
	{
		actual++;
		cub->weapons.s_nb = actual;
		if (actual == 5)
			cub->weapons.up = FALSE;
	}
	else
	{
		actual--;
		cub->weapons.s_nb = actual;
		if (actual == 1)
			cub->weapons.up = TRUE;
	}
	return (actual);
}

/**
 * @brief Returns the weapon frame image matching the given frame index.
 *
 * @param cub Pointer to the main game structure.
 * @param actual The frame number (1–5).
 * @return t_img* Pointer to the corresponding weapon image.
 */
static t_img	*change_frame(t_cub *cub, int actual)
{
	if (actual == 1)
		return (&cub->weapons.img_w1);
	else if (actual == 2)
		return (&cub->weapons.img_w2);
	else if (actual == 3)
		return (&cub->weapons.img_w3);
	else if (actual == 4)
		return (&cub->weapons.img_w4);
	else
		return (&cub->weapons.img_w5);
}
