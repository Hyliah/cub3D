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

void	cal_map(t_cub *cub)
{
	cub->player.map_x = (int)cub->player.pos_x;
	cub->player.map_y = (int)cub->player.pos_y;
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