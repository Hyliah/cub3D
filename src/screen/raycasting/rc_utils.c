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

static int	init_wall(t_cub *cub, t_img *img, char *xpm, int exit);

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
	if (init_wall(cub, &cub->graphic.img_e, cub->setting.tex_ea, 12))
		return (1);
	if (init_wall(cub, &cub->graphic.img_s, cub->setting.tex_so, 13))
		return (1);
	if (init_wall(cub, &cub->graphic.img_w, cub->setting.tex_we, 14))
		return (1);
	if (init_wall(cub, &cub->graphic.img_n, cub->setting.tex_no, 15))
		return (1);
	return (0);
}

static int	init_wall(t_cub *cub, t_img *img, char *xpm, int exit)
{
	int	x;
	int	y;

	x = 1024;
	y = 1024;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	if (!img->img_ptr)
		return (free_mid_init(cub, exit), 1);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
	return (0);
}
