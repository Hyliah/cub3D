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

void	cal_step(t_cub *cub)
{
	if (cub->player.ray_dir_x < 0)
		cub->player.step_x = -1;
	else
		cub->player.step_x = 1;
	if (cub->player.ray_dir_y < 0)
		cub->player.step_y = -1;
	else
		cub->player.step_y = 1;
}
