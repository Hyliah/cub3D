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

void	cal_all(t_cub *cub, int x, int side)
{
	cal_camera_x(cub, x);
    cal_ray_dir(cub);
    cal_delta_dist(cub);
    cal_map(cub);
    cal_step(cub);
    cal_side_dist(cub);
    cal_perp_wall_dist(cub, side);
    cal_line_height(cub);
}

/*
1 - camera x
2 - ray dir xy
3 - delta dist xy
4 - mapx mapy
5 - step
6 - side dist xy
7 - perp_wall_dist
8 - line_height
*/