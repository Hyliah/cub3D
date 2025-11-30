/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:37:25 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:41:53 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	rotate_player(t_cub *cub, double angle);

/**
 * @brief Handles mouse press events.
 *
 * Activates mouse-based rotation on left click.
 *
 * @param button Mouse button identifier.
 * @param x Mouse x-position.
 * @param y Mouse y-position.
 * @param cub Main game structure.
 * @return int Always 0.
 */
int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)y;
	if (button == 1)
	{
		cub->mouse.pressed = TRUE;
		cub->mouse.last_x = x;
	}
	return (0);
}

/**
 * @brief Handles mouse release events.
 *
 * Stops mouse-driven rotation when left click is released.
 *
 * @param button Mouse button identifier.
 * @param x Mouse x-position.
 * @param y Mouse y-position.
 * @param cub Main game structure.
 * @return int Always 0.
 */
int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->mouse.pressed = FALSE;
	return (0);
}

/**
 * @brief Handles mouse movement while left button is pressed.
 *
 * Rotates the player based on horizontal movement delta.
 * 0.3 is chosen for the best movement experience
 *
 * @param x Mouse x-position.
 * @param y Mouse y-position.
 * @param cub Main game structure.
 * @return int Always 0.
 */
int	mouse_move(int x, int y, t_cub *cub)
{
	int		dx;
	double	angle;

	(void)y;
	if (!cub->mouse.pressed)
		return (0);
	dx = x - cub->mouse.last_x;
	cub->mouse.last_x = x;
	angle = dx * 0.03;
	rotate_player(cub, angle);
	return (0);
}

/**
 * @brief Rotates the player by a given angle.
 *
 * @param cub Pointer to the main game structure.
 * @param angle Angle delta in degrees.
 */
static void	rotate_player(t_cub *cub, double angle)
{
	double	old_angle;
	double	new_angle;

	old_angle = cub->player.angle;
	new_angle = old_angle + (angle * 3);
	cub->player.angle = new_angle;
}
