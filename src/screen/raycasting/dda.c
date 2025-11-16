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

static void	check_doors_hit(t_cub *cub, int *hit);

int	dda(t_cub *cub)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (cub->player.side_dist_x < cub->player.side_dist_y)
		{
			cub->player.side_dist_x += cub->player.delta_dist_x;
			cub->player.map_x += cub->player.step_x;
			side = 0;
		}
		else
		{
			cub->player.side_dist_y += cub->player.delta_dist_y;
			cub->player.map_y += cub->player.step_y;
			side = 1;
		}
		check_doors_hit(cub, &hit);
	}
	return (side);
}

static void	check_doors_hit(t_cub *cub, int *hit)
{
	if (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == 'D'
			&& cub->map.is_door_open == FALSE)
		cub->player.is_door = TRUE;
	else
		cub->player.is_door = FALSE;
	if (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == '1'
		|| (cub->map.map_tab[cub->player.map_y][cub->player.map_x] == 'D'
		&& cub->map.is_door_open == FALSE))
		*hit = 1;
}
