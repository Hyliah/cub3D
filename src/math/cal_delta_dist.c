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

void	cal_delta_dist(t_cub *cub)
{
	if (cub->player.ray_dir_x == 0.0f)
		cub->player.delta_dist_x = 1e30f;
	else
		cub->player.delta_dist_x = fabsf(1.0f / cub->player.ray_dir_x);
	if (cub->player.ray_dir_y == 0.0f)
		cub->player.delta_dist_y = 1e30f;
	else
		cub->player.delta_dist_y = fabsf(1.0f / cub->player.ray_dir_y);
}
