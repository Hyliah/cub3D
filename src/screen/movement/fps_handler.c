/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:47:38 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 01:47:40 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	get_current_time(void);

/**
 * @brief Limits the FPS to a maximum value (60 FPS).
 *
 * Uses sleeping to prevent overly fast rendering loops.
 *
 * @param cub Main game structure.
 */
void	limit_fps(t_cub *cub)
{
	double	current_time;
	double	frame_duration_ms;
	double	elapsed;
	int		max_fps;

	max_fps = 60;
	current_time = get_current_time();
	frame_duration_ms = 1000.0 / max_fps;
	elapsed = current_time - cub->fps.start_time;
	if (elapsed < frame_duration_ms)
		usleep((useconds_t)((frame_duration_ms - elapsed) * 1000.0));
	cub->fps.start_time = get_current_time();
}

/**
 * @brief Updates the frame time used for movement and animation calculations.
 *
 * Computes time since previous frame in seconds.
 *
 * @param cub Pointer to the main game structure.
 */
void	frame_time(t_cub *cub)
{
	double	current_time;

	current_time = get_current_time();
	cub->fps.frame_time = (current_time - cub->fps.old_time) / 1000.0;
	cub->fps.old_time = current_time;
}

/**
 * @brief Returns current time in milliseconds.
 *
 * Uses gettimeofday() to compute a timestamp.
 *
 * @return double Current time in milliseconds.
 */
static double	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		printf("issue while getting time\n");
		return (0);
	}
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}
