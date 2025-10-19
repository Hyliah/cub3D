/*****************************************************************************/
/*                                                                           */
/*                                                                           */
/*                       LES CODEUSES DU DIMANCHE                            */
/*                               FONT UN                                     */
/*                        __  _  _  ___  ___  ___                            */
/*                       / _)( )( )(  ,)(__ )(   \                           */
/*                      ( (_  )()(  ) ,\ (_ \ ) ) )                          */
/*                       \__) \__/ (___/(___/(___/                           */
/*                                                                           */
/*****************************************************************************/

#include "cub.h"

static double	get_current_time(void);

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

void	frame_time(t_cub *cub)
{
	double	current_time;

	current_time = get_current_time();
	cub->fps.frame_time = (current_time - cub->fps.old_time) / 1000.0;
	cub->fps.old_time = current_time;
}

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
