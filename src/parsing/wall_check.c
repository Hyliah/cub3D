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

// liberation de copy tab pour eviter leaks etc ... 
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
		//print_tab(cpy_tab);
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
				map[y][x] = '0';
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
// Nouvelle version car invalid read avec Valgrind. 
// Lecture sans depasser avec src_len ( refacto dans alloc_map)

// static char	**cpy_map(t_cub *cub)
// {
// 	int		i;
// 	int		j;
// 	size_t	src_len;
// 	char	**cpy_map;

// 	i = 0;
// 	cpy_map = malloc(sizeof(char *) * (cub->map.height + 1));
// 	if (!cpy_map)
// 		return (NULL);
// 	while (i < cub->map.height)
// 	{
// 		cpy_map[i] = malloc(cub->map.width + 1);
// 		if (cpy_map[i] == NULL)
// 			return (free_mid_tab(cub, &cpy_map, i), NULL);
// 		src_len = ft_strlen(cub->map.map_tab[i]);
// 		j = 0;
// 		while (j < (int)cub->map.width)
// 		{
// 			if ((size_t)j < src_len)
// 				cpy_map[i][j] = cub->map.map_tab[i][j];
// 			else
// 				cpy_map[i][j] = ' ';
// 			j++;
// 		}
// 		cpy_map[i][j] = '\0';
// 		i++;
// 	}
// 	cpy_map[i] = 0;
// 	return (cpy_map);
// }

// originale hygie
// static char	**cpy_map(t_cub *cub)
// {
// 	int		i;
// 	char	**cpy_map;

// 	i = 0;
// 	cpy_map = malloc(sizeof(char *) * (cub->map.height + 1));
// 	if (!cpy_map)
// 		return (NULL);
// 	while (i < cub->map.height)
// 	{
// 		cpy_map[i] = ft_strdup(cub->map.map_tab[i]);
// 		if (cpy_map[i] == NULL)
// 			return (free_mid_tab(cub, &cpy_map, i), NULL);
// 		i++;
// 	}
// 	cpy_map[i] = 0;
// 	return (cpy_map);
// }

// static void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab && tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }

// int	is_invalid_position(char **map, int y, int x)
// {
// 	int	len;
// 	int	above_len;
// 	int	below_len;

// 	len = ft_strlen(map[y]);
// 	if (y > 0 && map[y - 1])
// 		above_len = ft_strlen(map[y - 1]);
// 	else
// 		above_len = 0;
// 	if (map[y + 1])
// 		below_len = ft_strlen(map[y + 1]);
// 	else
// 		below_len = 0;
// 	if (y == 0 || x == 0 || !map[y + 1]
// 		|| x >= len - 1 || x >= above_len || x >= below_len)
// 		return (1);
// 	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
// 		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
// 		return (1);
// 	return (0);
// }

// void	check_line_walls(t_cub *cub, int y)
// {
// 	int		x;
// 	char	**map;

// 	map = cub->map.map_tab;
// 	x = 0;
// 	while (map[y][x])
// 	{
// 		if ((map[y][x] == '0' || map[y][x] == 'D')
// 			&& is_invalid_position(map, y, x))
// 		{
// 			ft_error(ERR_MAP_WALLS);
// 			clean_exit_parsing(cub);
// 		}
// 		x++;
// 	}
// }

// void	check_wall(t_cub *cub)
// {
// 	int		y;
// 	char	**map;

// 	map = cub->map.map_tab;
// 	y = 0;
// 	while (map[y])
// 	{
// 		check_line_walls(cub, y);
// 		y++;
// 	}
// }