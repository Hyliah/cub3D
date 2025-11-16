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

void	cal_view(t_cub *cub)
{
	float	angle;
	float	fov;

	angle = cub->player.angle * M_PI / 180.0;
	fov = 0.66;
	cub->player.dir_x = cos(angle);
	cub->player.dir_y = -sin(angle);
	cub->player.pl_x = sin(angle) * fov;
	cub->player.pl_y = cos(angle) * fov;
}
