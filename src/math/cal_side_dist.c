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

void	cal_side_dist(t_cub *cub)
{
	if (cub->player.ray_dir_x < 0)
		cub->player.side_dist_x
			= ((cub->player.pos_x - (float)cub->player.map_x)
				* cub->player.delta_dist_x);
	else
		cub->player.side_dist_x
			= ((cub->player.map_x + 1.0 - cub->player.pos_x)
				* cub->player.delta_dist_x);
	if (cub->player.ray_dir_y < 0)
		cub->player.side_dist_y
			= ((cub->player.pos_y - (float)cub->player.map_y)
				* cub->player.delta_dist_y);
	else
		cub->player.side_dist_y
			= ((cub->player.map_y + 1.0 - cub->player.pos_y)
				* cub->player.delta_dist_y);
}
