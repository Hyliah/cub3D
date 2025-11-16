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

// dessiner le petit losange
void	mm_player_draw(t_cub *cub, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	thick;

	x = (int)(cub->player.pos_x * (float)cub->mmap.mm_sqr);
	y = (int)(cub->player.pos_y * (float)cub->mmap.mm_sqr);
	thick = (cub->mmap.mm_sqr - 1) / 2;
	i = -thick;
	while (i <= thick)
	{
		j = -thick;
		while (j <= thick)
		{
			if (abs(i) + abs(j) <= thick)
				set_pixel(&cub->mmap.img_player, (x + i), (y + j), color);
			j++;
		}
		i++;
	}
}
