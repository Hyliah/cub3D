/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:33:49 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:37:19 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	cal_speed(t_cub *cub);
static t_bool	safe_move(t_cub *cub, float new_x, float new_y);
static void		move(t_cub *cub, float direction);
static void		change_angle_merge(t_cub *cub);

/**
 * @brief Handles all player movement and rotation per frame.
 *
 * Processes WASD movement, diagonals, and rotation.
 * Secures opposites movement AD or WS
 * 
 * @param cub Main game structure.
 */
void	move_player(t_cub *cub)
{
	if (cub->game_on == TRUE)
	{
		if ((cub->key.k_a && cub->key.k_d) || (cub->key.k_s && cub->key.k_w))
			change_angle_merge(cub);
		else
		{
			if (cub->key.k_a && cub->key.k_w)
				move(cub, cub->player.angle + 45.0f);
			else if (cub->key.k_d && cub->key.k_w)
				move(cub, cub->player.angle + 315.0f);
			else if (cub->key.k_d && cub->key.k_s)
				move(cub, cub->player.angle + 225.0f);
			else if (cub->key.k_a && cub->key.k_s)
				move(cub, cub->player.angle + 135.0f);
			else if (cub->key.k_a)
				move(cub, cub->player.angle + 90.0f);
			else if (cub->key.k_d)
				move(cub, cub->player.angle + 270.0f);
			else if (cub->key.k_s)
				move(cub, cub->player.angle + 180.0f);
			else if (cub->key.k_w)
				move(cub, cub->player.angle);
			change_angle_merge(cub);
		}
	}
}

/**
 * @brief Updates player rotation based on arrow keys and merges screen updates.
 *
 * @param cub Main game structure.
 */
static void	change_angle_merge(t_cub *cub)
{
	double	old_angle;
	double	new_angle;

	if (cub->key.k_le && cub->key.k_ri)
		merge_screens(cub);
	else
	{
		old_angle = cub->player.angle;
		if (cub->key.k_le)
			new_angle = old_angle + 4;
		else if (cub->key.k_ri)
			new_angle = old_angle - 4;
		else
			new_angle = old_angle;
		if (new_angle > 360)
			new_angle = 0;
		else if (new_angle < 0)
			new_angle = 360;
		cub->player.angle = new_angle;
		merge_screens(cub);
	}
}

/**
 * @brief Moves the player in the given direction if no collision occurs.
 *
 * Computes the new position, checks collisions, and applies movement.
 *
 * @param cub Main game structure.
 * @param direction Angle in degrees.
 */
static void	move(t_cub *cub, float direction)
{
	double	speed;
	float	angle;
	float	new_x;
	float	new_y;

	if (direction > 360)
		direction = direction - 360;
	angle = direction * M_PI / 180.0;
	speed = cal_speed(cub);
	new_x = cub->player.pos_x + (cos(angle)) * speed;
	new_y = cub->player.pos_y + (-sin(angle)) * speed;
	if (safe_move(cub, new_x, new_y))
	{
		mm_player_draw(cub, 0x0000000);
		cub->player.pos_x = new_x;
		cub->player.pos_y = new_y;
		mm_player_draw(cub, 0x622416);
	}
}

/**
 * @brief Computes player movement speed based on frame time and key inputs.
 *
 * Sprinting increases speed by 2.5; moving backward reduces speed by 0.5.
 * Checks for overkill movement speed.
 *
 * @param cub Pointer to the main game structure.
 * @return double The computed movement speed.
 */
static double	cal_speed(t_cub *cub)
{
	double	speed;

	frame_time(cub);
	if (cub->key.k_sh && cub->key.k_w)
	{
		speed = cub->fps.frame_time * 4.0;
	}
	else if (cub->key.k_s)
		speed = cub->fps.frame_time * 0.75;
	else
		speed = cub->fps.frame_time * 1.5;
	if (speed < 0.1)
		return (speed);
	else
		return (0.15);
}

/**
 * @brief Checks if a movement to the given coordinates is allowed.
 *
 * Prevents walking through walls ('1') or closed doors ('D').
 *
 * @param cub Main game structure.
 * @param new_x Target X coordinate.
 * @param new_y Target Y coordinate.
 * @return t_bool TRUE if the move is safe, FALSE otherwise.
 */
static t_bool	safe_move(t_cub *cub, float new_x, float new_y)
{
	float	r;

	r = 0.05f;
	if (cub->map.map_tab[(int)(new_y)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y + r)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y - r)][(int)(new_x)] == '1'
		|| cub->map.map_tab[(int)(new_y)][(int)(new_x + r)] == '1'
		|| cub->map.map_tab[(int)(new_y)][(int)(new_x - r)] == '1')
		return (FALSE);
	if (cub->map.is_door_open == FALSE)
	{
		if (cub->map.map_tab[(int)(new_y)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y + r)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y - r)][(int)(new_x)] == 'D'
			|| cub->map.map_tab[(int)(new_y)][(int)(new_x + r)] == 'D'
			|| cub->map.map_tab[(int)(new_y)][(int)(new_x - r)] == 'D')
			return (FALSE);
	}
	return (TRUE);
}
