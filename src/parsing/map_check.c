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
	check_line_empty_in_map(cub); // ne fontcionne pas - a checker again !!!!
	// check_player(cub);
	// check_wall(cub);
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
// // version de debu pour test 
// void	check_line_empty_in_map(t_cub *cub)
// {
// 	int	y;
// 	int	empty;

// 	y = 0;
// 	empty = 0;
// 	while (cub->map.map_tab[y])
// 	{
// 		// Debug : afficher la ligne avec ses caractères spéciaux visibles
// 		printf("DEBUG map line %d -> '%s'\n", y, cub->map.map_tab[y]);

// 		// Vérifie si la ligne est vide (ou contient seulement des espaces/tabs)
// 		int line_empty = 1;
// 		for (int i = 0; cub->map.map_tab[y][i]; i++)
// 		{
// 			if (cub->map.map_tab[y][i] != ' ' && cub->map.map_tab[y][i] != '\t')
// 			{
// 				line_empty = 0;
// 				break;
// 			}
// 		}

// 		if (line_empty)
// 		{
// 			printf("DEBUG: ligne %d vide détectée\n", y);
// 			empty = 1;
// 		}
// 		else if (empty == 1)
// 		{
// 			// Une ligne non vide après une ligne vide : erreur map
// 			fprintf(stderr, "Error: ligne non vide après une ligne vide à la ligne %d\n", y);
// 			ft_error(ERR_MAP_LINE);
// 		}
// 		y++;
// 	}
// }


// Pas de ligen vide A L INTERIEUR la map 
void	check_line_empty_in_map(t_cub *cub)
{
	int	y;
	int	empty;

	y = 0;
	empty = 0;
	while ( cub->map.map_tab[y])
	{
		if ( is_empty_line(cub->map.map_tab[y]))
			empty = 1;
		else if (empty == 1)
		{
			ft_error(ERR_MAP_LINE);
		}
		y++;
	}
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

// si on veut faire un flood fill, faire apres avoir determine la position du player
// faire copie de map pour ne pas modif l original en faisant le floofill avec des '*'

// si on faiyt un flood fill du coup check wall devient inutile ? Flood fill better ? 