/* voir ca pour le pixel put */
// unsigned int	my_mlx_pixel_get(t_img *data, int x, int y)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
// 	return (*(unsigned int *)dst);
// }

// void	my_mlx_area_put(t_img *d, t_vector p, t_vector dim, int c)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < dim.y)
// 	{
// 		x = -1;
// 		while (++x < dim.x)
// 			my_mlx_pixel_put(d, p.x + x, p.y + y, c);
// 	}
// }

// void	mlx_img_to_img(int p[2], t_img img[2], int c1)
// {
// 	int	xy[2];
// 	int	color;

// 	xy[1] = -1;
// 	while (++xy[1] < img[0].height)
// 	{
// 		xy[0] = -1;
// 		while (++xy[0] < img[0].width)
// 		{
// 			if (xy[0] + p[0] >= 0 && xy[1] + p[1] >= 0)
// 			{
// 				color = my_mlx_pixel_get(&img[0], xy[0], xy[1]);
// 				if (color != c1)
// 					my_mlx_pixel_put(&img[1], xy[0] + p[0], 
// 						xy[1] + p[1], color);
// 			}
// 		}
// 	}
// }










// void draw_minimap(t_cub *cub)
// {
// 	int	i;
// 	int	j;
// 	int tile_size;
// 	int offset_x;
// 	int offset_y;

// 	tile_size = 9;
// 	offset_x = cub->graphic.s_width - cub->map.width * tile_size - 10;
// 	offset_y = 10;
// 	i = 0;
// 	while (i < cub->map.height)
// 	{
// 		j = 0;
// 		while (j < cub->map.width)
// 		{
// 			if (cub->map.map_tab[i][j] == '1')
// 				draw_square(&cub->graphic, offset_x + j * tile_size, offset_y + i * tile_size, tile_size, 0xFF00FF);
// 			else
// 				draw_square(&cub->graphic, offset_x + j * tile_size, offset_y + i * tile_size, tile_size, 0x000000);
// 			j++;
// 		}
// 		i++;
// 	}

// 	int player_x = offset_x + (int)(cub->player.pos_x * tile_size);
// 	int player_y = offset_y + (int)(cub->player.pos_y * tile_size);
// 	draw_square(&cub->graphic, player_x, player_y, tile_size, 0xFF0000);
// }

// static void draw_square(t_graphic *g, int start_x, int start_y, int size, int color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < size)
// 	{
// 		x = 0;
// 		while (x < size)
// 		{
// 			pixel_put(g, start_x + x, start_y + y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }





/* MAYBEEEEEE */
// static void	draw_mmap_background_and_border(t_cub *cub, int x_offset, int y_offset)
// {
// 	int	x;
// 	int	y;
// 	int	width = cub->mmap.img_mmap.width;
// 	int	height = cub->mmap.img_mmap.height;

// 	// fond gris foncé (semi-transparent visuellement)
// 	int	background_color = 0x222222;
// 	int	border_color = 0xAAAAAA;

// 	// fond
// 	for (y = 0; y < height; y++)
// 	{
// 		for (x = 0; x < width; x++)
// 			set_pixel(&cub->graphic.img_screen, x + x_offset, y + y_offset, background_color);
// 	}

// 	// bordure (1 px)
// 	for (x = -1; x <= width; x++)
// 	{
// 		set_pixel(&cub->graphic.img_screen, x + x_offset, -1 + y_offset, border_color); // haut
// 		set_pixel(&cub->graphic.img_screen, x + x_offset, height + y_offset, border_color); // bas
// 	}
// 	for (y = -1; y <= height; y++)
// 	{
// 		set_pixel(&cub->graphic.img_screen, -1 + x_offset, y + y_offset, border_color); // gauche
// 		set_pixel(&cub->graphic.img_screen, width + x_offset, y + y_offset, border_color); // droite
// 	}
// }