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

/* MINI MAP VERSION PIXEL_PUT*/

static void mm_drawing(t_cub *cub);
static void	mm_draw_pixel(t_cub *cub, int color, int x, int y);

void	mm_creation(t_cub *cub)
{
	mm_drawing(cub);
	mm_player(cub);
	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, cub->mmap.player.img_ptr, 0, 0);
}

static void mm_drawing(t_cub *cub)
{
	int	y;
	int	x;

	printf("height : %d\n", cub->map.height);
	printf("width: %d\n", cub->map.width);
	y = 0;
	while (y < cub->map.width)
	{
		puts("0");
		x = 0;
		while (x < cub->map.height)
		{
			puts("1");
			if (cub->map.map_tab[x][y] == '1')
				mm_draw_pixel(cub, 0x275E1F, x, y);
			else if (cub->map.map_tab[x][y] == '0')
				mm_draw_pixel(cub, 0xE4C095, x, y);
			else if (cub->map.map_tab[x][y] == 'N')
				mm_draw_pixel(cub, 0x622416, x, y);
			x++;
		}
		y++;
	}
}

static void	mm_draw_pixel(t_cub *cub, int color, int x, int y)
{
	int	px;
	int	py;
	int size_sq;

	py = 0;
	size_sq = cub->mmap.mm_square;
	while (py < size_sq)
	{
		px = 0;
		while (px < size_sq)
		{
			set_pixel(&cub->mmap.minimap, (y * size_sq + py), (x * size_sq + px), color);
			px++;
		}
		py++;
	}
}


	// int x = 960;
	// int y = 540;

	// set_pixel(&cub->graphic.screen, x, y, 0xFF0000);

	// mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, cub->graphic.screen.img_ptr, 0, 0);




	// int x = 470;
	// int y = 230;

	// set_pixel(&cub->mmap.minimap, x, y, 0xFF00FF);

	// mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, cub->mmap.minimap.img_ptr, 0, 0);
	// printf("square : %d\n", cub->mmap.mm_square);
	// printf("height : %d\n", cub->mmap.mm_height);

	// //set_pixel(&cub->mmap.minimap, x, y, 0xFF00FF);
	//mm_drawing(cub);

	// int x = 120;
	// int y = 40;

	// set_pixel(&cub->graphic.screen, x, y, 0xFF0000);

	// mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, cub->graphic.screen.img_ptr, 0, 0);





/* MINI MAP VERSION SO_LONG*/

// static void	create_mini_minimap(t_graphic *graphic, t_map *map);
// static void	create_maxi_minimap(t_graphic *graphic, t_map *map);

// void	create_minimap(t_graphic *graphic, t_map *map)
// {
// 	if (map->height > 20 || map->width > 45)
// 		graphic->maxi_mm = FALSE;
// 	else
// 		graphic->maxi_mm = TRUE;
// 	if (graphic->maxi_mm == TRUE)
// 		create_maxi_minimap(graphic, map);
// 	else
// 		create_mini_minimap(graphic, map);
// }

// static void	create_mini_minimap(t_graphic *graphic, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	y;

// 	x = 9;
// 	y = 9;
// 	i = 0;
// 	graphic->mm_p = mlx_xpm_file_to_image(graphic->mlx_ptr, MMP, &x, &y);
// 	graphic->mm_f = mlx_xpm_file_to_image(graphic->mlx_ptr, MMF, &x, &y);
// 	graphic->mm_w = mlx_xpm_file_to_image(graphic->mlx_ptr, MMW, &x, &y);
// 	while (map->map_tab[i])
// 	{
// 		j = 0;
// 		while (map->map_tab[i][j])
// 		{
// 			create_tile(graphic, map->map_tab[i][j], j * 9, i * 9);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	create_maxi_minimap(t_graphic *graphic, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	y;

// 	x = 27;
// 	y = 27;
// 	i = 0;
// 	graphic->mm_p = mlx_xpm_file_to_image(graphic->mlx_ptr, BMP, &x, &y);
// 	graphic->mm_f = mlx_xpm_file_to_image(graphic->mlx_ptr, BMF, &x, &y);
// 	graphic->mm_w = mlx_xpm_file_to_image(graphic->mlx_ptr, BMW, &x, &y);
// 	while (map->map_tab[i])
// 	{
// 		j = 0;
// 		while (map->map_tab[i][j])
// 		{
// 			create_tile(graphic, map->map_tab[i][j], j, i);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	create_tile(t_graphic *graphic, char c, int j, int i)
// {
// 	int x;
// 	int y;
// 	if (graphic->maxi_mm == TRUE)
// 	{
// 		x = 27;
// 		y = 27;
// 	}
// 	else
// 	{
// 		x = 9;
// 		y = 9;
// 	}
// 	if (c == '1')
// 		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
// 			graphic->mm_w, j * x, i * y);
// 	if (c == '0')
// 		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
// 			graphic->mm_f, j * x, i * y);
// 	if (c == 'E' || c == 'W' || c == 'N' || c == 'S')
// 		mlx_put_image_to_window(graphic->mlx_ptr, graphic->win_ptr,
// 			graphic->mm_p, j * x, i * y);
// }
