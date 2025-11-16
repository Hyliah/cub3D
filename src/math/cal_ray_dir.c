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

void	cal_ray_dir(t_cub *cub)
{
	cub->player.ray_dir_x
		= cub->player.dir_x + cub->player.pl_x * cub->player.cam_x;
	cub->player.ray_dir_y
		= cub->player.dir_y + cub->player.pl_y * cub->player.cam_x;
}
