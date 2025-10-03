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

static int	ft_abs(int i);
static void	mm_player_draw(t_cub *cub, int x, int y, int thick);

void	mm_player(t_cub *cub)
{
	int	x;
	int	y;
	int	thick; // -> thickness du point du joueur -> correspond a (sqr -1 /2)
	// set de la position du pixel central du joueur
	x = (int)(cub->player.pos_x * (float)cub->mmap.mm_sqr);
	y = (int)(cub->player.pos_y * (float)cub->mmap.mm_sqr);
	thick = (cub->mmap.mm_sqr - 1) / 2;
	// message d erreur pour au cas ou bloquer la taille de la map
	if (thick < 1)
		printf ("WARNING FAIRE MAP PLUS PETITE");
	mm_player_draw(cub, x, y, thick);
}

static void	mm_player_draw(t_cub *cub, int x, int y, int thick)
{
	int	i;
	int	j;

	i = -thick;
	while (i <= thick)
	{
		j = -thick;
		while (j <= thick)
		{
			if (ft_abs(i) + ft_abs(j) <= thick)
				set_pixel(&cub->mmap.img_player, (x + i), (y + j), 0x622416);
			j++;
		}
		i++;
	}
}

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
//int	rec_count(char **map_tab, int x, int y, char c)
// {
// 	static int	count = 0;

// 	if (map_tab[y][x] == '1' || map_tab[y][x] == '*')
// 		return (count);
// 	if (map_tab[y][x] == c)
// 		count++;
// 	if (map_tab[y][x] != '1')
// 		map_tab[y][x] = '*';
// 	rec_count(map_tab, x + 1, y, c);
// 	rec_count(map_tab, x - 1, y, c);
// 	rec_count(map_tab, x, y + 1, c);
// 	rec_count(map_tab, x, y - 1, c);
// 	return (count);
// }