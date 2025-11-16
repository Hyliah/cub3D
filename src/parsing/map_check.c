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
				&& c != 'E' && c != 'W' && c != 'D' && c != ' ' && c != '\n')
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

int	is_map_bottom_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
