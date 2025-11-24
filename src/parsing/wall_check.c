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

static void		fill_blank(t_cub *cub, char **map);
static t_bool	flood_fill(t_cub *cub, char **map, int x, int y);

void	check_wall(t_cub *cub)
{
	char	**cpy_tab;
	int		x;
	int		y;

	x = (int)cub->player.pos_x;
	y = (int)cub->player.pos_y;
	cpy_tab = cpy_map(cub);
	if (!cpy_tab)
	{
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing(cub);
	}
	fill_blank(cub, cpy_tab);
	if (flood_fill(cub, cpy_tab, x, y) == FALSE)
	{
		free_tab(&cpy_tab);
		ft_error(ERR_MAP_WALLS);
		clean_exit_parsing(cub);
	}
	free_tab(&cpy_tab);
}

static t_bool	flood_fill(t_cub *cub, char **map, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = cub->map.width;
	max_y = cub->map.height;
	if (x < 0 || y < 0 || x >= max_x || y >= max_y)
		return (FALSE);
	if (map[y][x] == '1')
		return (TRUE);
	if (map[y][x] == '*')
		return (TRUE);
	if (map[y][x] == 'V')
		return (FALSE);
	map[y][x] = '*';
	if (!flood_fill(cub, map, x + 1, y))
		return (FALSE);
	if (!flood_fill(cub, map, x - 1, y))
		return (FALSE);
	if (!flood_fill(cub, map, x, y + 1))
		return (FALSE);
	if (!flood_fill(cub, map, x, y - 1))
		return (FALSE);
	return (TRUE);
}

static void	fill_blank(t_cub *cub, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (map[y][x] == ' ')
				map[y][x] = 'V';
			x++;
		}
		y++;
	}
}

void	check_size(t_cub *cub)
{
	if (cub->map.height > 100 || cub->map.width > 200)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putendl_fd("Map too big", 2);
		clean_exit_parsing(cub);
	}
}
