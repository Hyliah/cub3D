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

// faire comme so long, une copie de la map ? 
// la fonction recursive de floodfill 
// fonction avec check valid map pour tout check (sur so long c etait path)


void	flood_fill(t_cub *cub, int y, int x)
{
	if (y < 0 || x < 0 || y >= cub->map.height || x >= cub->map.width)
		return ;
	if (cub->map.map_tab[y][x] == ' ' || cub->map.map_tab[y][x] == '1'
		|| cub->map.map_tab[y][x] == '*')
		return ;
	cub->map.map_tab[y][x] = '*';
	flood_fill(cub, y + 1, x);
	flood_fill(cub, y - 1, x);
	flood_fill(cub, y, x + 1);
	flood_fill(cub, y, x - 1);
}

int	is_touching_void(t_cub *cub)
{
	int		y;
	int		x;
	char	**map;

	map = cub->map.map_tab;
	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (map[y][x] == '*' && (y == 0 || x == 0 ||
				y == cub->map.height - 1 || x == cub->map.width - 1 ||
				map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
				map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
void	check_valid_map_flood(t_cub *cub)
{
	char	**dup;
	double	py;
	double	px;

	py = cub->player.pos_y;
	px = cub->player.pos_x;
	if (py < 0 || px < 0)
	{
		ft_error(ERR_PLAYER);
		clean_exit_parsing(cub);
	}
	dup = dup_tab(cub->map.map_tab);
	if (!dup)
	{
		//ERR
		clean_exit_parsing(cub);
	}
	cub->map.map_tab = dup;
	flood_fill(cub, py, px);
	if (is_touching_void(cub))
	{
		free_tab(&dup);
		ft_error(ERR_MAP_WALLS);
		clean_exit_parsing(cub);
	}
	free_tab(&dup);
}
// Compte le nombre de lignes dans un tableau 2D
int	tab_height(char **src)
{
	int	i = 0;
	while (src && src[i])
		i++;
	return (i);
}

// Duplique un tableau 2D de char **
char	**dup_tab(char **src)
{
	char	**dup;
	int		i;
	int		height;

	if (!src)
		return (NULL);
	height = tab_height(src);
	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(src[i]);
		if (!dup[i])
		{
			while (i > 0)
				free(dup[--i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
