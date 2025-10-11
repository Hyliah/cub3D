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

float	cal_side_dist(float pos, float map, float delta_dist, float ray_dir)
{
	if (ray_dir < 0)
		return ((pos - map) * delta_dist);
	else
		return ((map + 1.0 - pos) * delta_dist);
}
