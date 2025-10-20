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


// static void	fill_pixel(t_cub *cub, int x)
// {
// 	int	end;
// 	int	start;

// 	end = cal_range(cub, FALSE);
// 	start = cal_range(cub, TRUE);
// 	create_pixel_line(cub, x, start, end);
// }

// static int	cal_range(t_cub *cub, t_bool is_start)
// {
// 	int	result;

// 	if (is_start == TRUE)
// 	{
// 		result = -cub->player.line_height / 2 + cub->graphic.s_height / 2;
// 		if (result < 0)
// 			result = 0;
// 		return (result);
// 	}
// 	else
// 	{
// 		result = cub->player.line_height / 2 + cub->graphic.s_height / 2;
// 		if (result >= cub->graphic.s_height)
// 			result = cub->graphic.s_height - 1;
// 		return (result);
// 	}
// }

// static void	create_pixel_line(t_cub *cub, int x, int start, int end)
// {
// 	int	i;

// 	i = 0;
// 	while (i < start)
// 	{
// 		set_pixel(&cub->graphic.img_screen, x, i, cub->setting.c_color);
// 		i++;
// 	}
// 	while (i < end)
// 	{
// 		set_pixel(&cub->graphic.img_screen, x, i, 0xFF99FF);
// 		i++;
// 	}
// 	while (i < cub->graphic.s_height)
// 	{
// 		set_pixel(&cub->graphic.img_screen, x, i, cub->setting.f_color);
// 		i++;
// 	}
// }