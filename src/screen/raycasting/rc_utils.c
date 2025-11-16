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

static int	init_wall(t_cub *cub, t_img *img, char *xpm);

int	cal_range(t_cub *cub, t_bool is_start)
{
	int	result;

	if (is_start == TRUE)
	{
		result = -cub->player.line_height / 2 + cub->graphic.s_height / 2;
		if (result < 0)
			result = 0;
		return (result);
	}
	else
	{
		result = cub->player.line_height / 2 + cub->graphic.s_height / 2;
		if (result >= cub->graphic.s_height)
			result = cub->graphic.s_height - 1;
		return (result);
	}
}

int	init_walls(t_cub *cub)
{
	if (init_wall(cub, &cub->graphic.img_e, cub->setting.tex_ea))
		return (1);
	if (init_wall(cub, &cub->graphic.img_s, cub->setting.tex_so))
		return (1);
	if (init_wall(cub, &cub->graphic.img_w, cub->setting.tex_we))
		return (1);
	if (init_wall(cub, &cub->graphic.img_n, cub->setting.tex_no))
		return (1);
	if (init_wall(cub, &cub->graphic.img_door, DOOR))
		return (1);
	return (0);
}

static int	init_wall(t_cub *cub, t_img *img, char *xpm)
{
	int	x;
	int	y;

	x = 1024;
	y = 1024;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	if (!img->img_ptr)
	{
		ft_putendl_fd("Error: failed to load XPM texture.", 2);
		return (clean_exit(cub), 1);
	}
	img->addr_ptr = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_line, &img->endian);
	if (!img->addr_ptr)
	{
		ft_putendl_fd("Error: failed to get image data address.", 2);
		mlx_destroy_image(cub->graphic.mlx_ptr, img->img_ptr);
		img->img_ptr = NULL;
		return (clean_exit(cub), 1);
	}
	img->width = x;
	img->height = y;
	return (0);
}
