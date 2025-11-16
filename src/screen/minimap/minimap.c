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

static void	mm_drawing(t_cub *cub);
static void	mm_draw_mm_sqr(t_cub *cub, int color, int x, int y);

//voir l utilite de cette fonction peut etre la mixer dans create window
void	mm_creation(t_cub *cub)
{
	mm_drawing(cub);
	mm_player_draw(cub, 0x622416);
}

static void	mm_drawing(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < cub->map.height)
	{
		y = 0;
		while (y < cub->map.width
			&& cub->map.map_tab[x][y])
		{
			if (cub->map.map_tab[x][y] == '1')
				mm_draw_mm_sqr(cub, 0x4B6E49, x, y);
			if (cub->map.map_tab[x][y] == 'D')
				mm_draw_mm_sqr(cub, 0x499E49, x, y);
			else if (cub->map.map_tab[x][y] == '0'
				|| cub->map.map_tab[x][y] == 'N'
				|| cub->map.map_tab[x][y] == 'S'
				|| cub->map.map_tab[x][y] == 'E'
				|| cub->map.map_tab[x][y] == 'W')
				mm_draw_mm_sqr(cub, 0xC7CB9F, x, y);
			y++;
		}
		x++;
	}
}

static void	mm_draw_mm_sqr(t_cub *cub, int color, int x, int y)
{
	int	px;
	int	py;
	int	sqr;

	py = 0;
	sqr = cub->mmap.mm_sqr;
	while (py < sqr)
	{
		px = 0;
		while (px < sqr)
		{
			set_pixel(&cub->mmap.img_mmap,
				(y * sqr + py), (x * sqr + px), color);
			px++;
		}
		py++;
	}
}
