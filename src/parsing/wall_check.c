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

int	is_invalid_position(char **map, int y, int x)
{
	int	len;
	int	above_len;
	int	below_len;

	len = ft_strlen(map[y]);
	if (y > 0 && map[y - 1])
		above_len = ft_strlen(map[y - 1]);
	else
		above_len = 0;
	if (map[y + 1])
		below_len = ft_strlen(map[y + 1]);
	else
		below_len = 0;
	if (y == 0 || x == 0 || !map[y + 1]
		|| x >= len - 1 || x >= above_len || x >= below_len)
		return (1);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

void	check_line_walls(t_cub *cub, int y)
{
	int		x;
	char	**map;

	map = cub->map.map_tab;
	x = 0;
	while (map[y][x])
	{
		if ((map[y][x] == '0' || map[y][x] == 'D')
			&& is_invalid_position(map, y, x))
		{
			ft_error(ERR_MAP_WALLS);
			clean_exit_parsing(cub);
		}
		x++;
	}
}

void	check_wall(t_cub *cub)
{
	int		y;
	char	**map;

	map = cub->map.map_tab;
	y = 0;
	while (map[y])
	{
		check_line_walls(cub, y);
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
