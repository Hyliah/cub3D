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

float	cal_ray_dir(t_cub *cub)
{
	cub->player.ray_dir_x =
		cub->player.dir_x + cub->player.pl_x * cub->player.cam_x;
	cub->player.ray_dir_y =
		cub->player.dir_y + cub->player.pl_y * cub->player.cam_x;
}

/*
1 - camera x
2 - ray dir xy
3 - delta dist xy
4 - mapx mapy
5 - side dist xy
6 - perp_wall_dist
7 - line_height
*/