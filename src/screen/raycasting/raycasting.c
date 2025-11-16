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

void	raycasting(t_cub *cub)
{
	int	x;
	int	side;

	x = 0;
	cal_view(cub);
	while (x < cub->graphic.s_width)
	{
		cal_camera_x(cub, x);
		cal_ray_dir(cub);
		cal_map(cub);
		cal_delta_dist(cub);
		cal_step(cub);
		cal_side_dist(cub);
		side = dda(cub);
		cal_perp_wall_dist(cub, side);
		cal_line_height(cub);
		texture_cal(cub, x, side);
		x++;
	}
}
