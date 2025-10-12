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

int	dda(t_cub *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->player.side_dist_x < cub->player.side_dist_y)
		{
			cub->player.side_dist_x += cub->player.side_dist_x;
			cub->player.map_x += cub->player.step_x;
			side = 0;
		}
		else
		{
			cub->player.side_dist_y += cub->player.side_dist_y;
			cub->player.map_y += cub->player.step_y;
			side = 1;
		}
		if (cub->map.map_tab[cub->player.map_x][cub->player.map_y] > 0)
			hit = 1;
	}
	return (side);
}
