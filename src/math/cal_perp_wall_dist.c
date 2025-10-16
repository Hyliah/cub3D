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

void	cal_perp_wall_dist(t_cub *cub, int side)
{
	if (side == 0)
		cub->player.perp_wall_dist
			= cub->player.side_dist_x - cub->player.delta_dist_x;
	else
		cub->player.perp_wall_dist
			= cub->player.side_dist_y - cub->player.delta_dist_y;
}
