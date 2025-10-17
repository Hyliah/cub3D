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

static void	fill_pixel(t_cub *cub, int x);
static int	cal_range(t_cub *cub, t_bool is_start);
static void	create_pixel_line(t_cub *cub, int x, int start, int end);

void	raycasting(t_cub *cub)
{
	int x;
	int	side;

	x = 0;
	cal_view(cub);
	while (x < cub->graphic.s_width)
	{
		cal_camera_x(cub, x);
		cal_ray_dir(cub);
		cal_map(cub);
		cal_delta_dist(cub);
		cal_step(cub);
		cal_side_dist(cub);
		side = dda(cub);
		cal_perp_wall_dist(cub, side);
		cal_line_height(cub);
		fill_pixel(cub, x);
		x++;
	}
}

static void	fill_pixel(t_cub *cub, int x)
{
	int	end;
	int	start;

	end = cal_range(cub, FALSE);
	start = cal_range(cub, TRUE);
	create_pixel_line(cub, x, start, end);
}

static int	cal_range(t_cub *cub, t_bool is_start)
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

static void	create_pixel_line(t_cub *cub, int x, int start, int end)
{
	int	i;

	i = 0;
	while (i < start)
	{
		set_pixel(&cub->graphic.img_screen, x, i, cub->setting.c_color);
		i++;
	}
		while (i < end)
	{
		set_pixel(&cub->graphic.img_screen, x, i, 0xFF99FF);
		i++;
	}
		while (i < cub->graphic.s_height)
	{
		set_pixel(&cub->graphic.img_screen, x, i, cub->setting.f_color);
		i++;
	}
}
