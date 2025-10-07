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

void	check_map(t_cub *cub)
{
	check_invalid_char(cub);
	check_line_empty(cub);
	check_player(cub);
	check_wall(cub);
}

// -> validité des caracteres comme ds so_long mais avec 0, 1, N, S, E, W
void	check_invalid_char(t_cub *cub)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (cub->map.map_tab[y])
	{
		x = 0;
		while (cub->map.map_tab[y][x])
		{
			c = cub->map.map_tab[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != ' ')
			{
				ft_error(ERR_MAP_INVALID_CHAR);
				clean_exit_parsing(cub);
			}
			x++;
		}
		y++;
	}
}

void	check_line_empty(t_cub *cub)
{
	// Pas de ligen vide au milieu de la map 
}

// check validité des maps
// -> entourée de murs (1)
void	check_wall(t_cub *cub)
{
	int		y;
	int		x;
	char	**map;

	map = cub->map.map_tab;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1]
				|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
				|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
				{
					ft_error(ERR_MAP_WALLS);
					clean_exit_parsing(cub);
				}
			}
			x++;
		}
		y++;
	}
}

// faire comme so_long ? no player, too many player ?? 
void	check_player(t_cub *cub)
{
	// double boucle while y puis x
	// check si deja un joueur = erreur 
	// position a 0.5 ? 
	// definir direction de depart pour la struct player dir 
	// remplacer le joueur par le sol dans la map
	if (cub->player.has_player == 0)
	{
		ft_error(ERR_NO_PLAYER);
		clean_exit_parsing(cub);
	}
}

// check player a la fin

// si on veut faire un flood fill, faire apres avoir determine la position du player
// faire copie de map pour ne pas modif l original en faisant le floofill avec des '*'

// si on faiyt un flood fill du coup check wall devient inutile ? Flood fill better ? 