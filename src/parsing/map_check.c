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
	check_line_empty_in_map(cub);
	// check_player(cub);
	// check_wall(cub);
}

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
				&& c != 'E' && c != 'W' && c != ' ' && c != '\n')
			{
				ft_error(ERR_MAP_INVALID_CHAR);
				printf("Invalid char (ASCII %d) found at y=%d x=%d -> '%c'\n",
					c, y, x, c);
				clean_exit_parsing(cub);
			}
			x++;
		}
		y++;
	}
}

void	check_line_empty_in_map(t_cub *cub)
{
	int	y;
	int	map_ended;

	y = 0;
	map_ended = 0;
	while (cub->map.map_tab[y])
	{
		if (is_empty_line(cub->map.map_tab[y]))
		{
			if (!map_ended)
				map_ended = 1;
		}
		else
		{
			if (map_ended)
			{
				ft_error(ERR_MAP_LINE);
				clean_exit_parsing(cub);
			}
		}
		y++;
	}
}

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