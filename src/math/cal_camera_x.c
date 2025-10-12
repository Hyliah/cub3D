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

/* gerer les soucis de castage */
void	cal_camera_x(t_cub *cub, int x)
{
	cub->player.cam_x = (2 * x / cub->graphic.s_width - 1);
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