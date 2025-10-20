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

static void	init_wall(t_cub *cub, t_img *img, char *xpm);

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

void	init_walls(t_cub *cub)
{
	init_wall(cub, &cub->graphic.img_e, WTE);
	init_wall(cub, &cub->graphic.img_s, WTS);
	init_wall(cub, &cub->graphic.img_w, WTW);
	init_wall(cub, &cub->graphic.img_n, WTN);
}

static void	init_wall(t_cub *cub, t_img *img, char *xpm)
{
	int	x;
	int	y;

	x = 1024;
	y = 1024;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	// if (!img->img_ptr)
	// 	infructuous_smth;
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
}

