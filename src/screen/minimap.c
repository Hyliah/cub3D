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

static void	create_mini_minimap(t_graphic *graphic, t_map *map);
static void	create_maxi_minimap(t_graphic *graphic, t_map *map);

void	create_minimap(t_graphic *graphic, t_map *map)
{
	if (map->height > 20 || map->width > 45)
		graphic->maxi_mm = FALSE;
	else
		graphic->maxi_mm = TRUE;
	if (graphic->maxi_mm == TRUE)
		create_maxi_minimap(graphic, map);
	else
		create_mini_minimap(graphic, map);
}

static void	create_mini_minimap(t_graphic *graphic, t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 9;
	y = 9;
	i = 0;
	graphic->mm_p = mlx_xpm_file_to_image(graphic->mlx_ptr, MMP, &x, &y);
	graphic->mm_f = mlx_xpm_file_to_image(graphic->mlx_ptr, MMF, &x, &y);
	graphic->mm_w = mlx_xpm_file_to_image(graphic->mlx_ptr, MMW, &x, &y);
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			create_tile(graphic, map->map_tab[i][j], j * 9, i * 9);
			j++;
		}
		i++;
	}
}

static void	create_maxi_minimap(t_graphic *graphic, t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 27;
	y = 27;
	i = 0;
	graphic->mm_p = mlx_xpm_file_to_image(graphic->mlx_ptr, BMP, &x, &y);
	graphic->mm_f = mlx_xpm_file_to_image(graphic->mlx_ptr, BMF, &x, &y);
	graphic->mm_w = mlx_xpm_file_to_image(graphic->mlx_ptr, BMW, &x, &y);
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			create_tile(graphic, map->map_tab[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	create_tile(t_graphic *graphic, char c, int j, int i)
{
	int x;
	int y;
	if (graphic->maxi_mm == TRUE)
	{
		x = 27;
		y = 27;
	}
	else
	{
		x = 9;
		y = 9;
	}
	if (c == '1')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->mm_w, j * x, i * y);
	if (c == '0')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->mm_f, j * x, i * y);
	if (c == 'E' || c == 'W' || c == 'N' || c == 'S')
		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
			graphic->mm_p, j * x, i * y);
}
