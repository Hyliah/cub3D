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

static t_img	*choose_wall(t_cub *cub, int side);
static void		fill_pixels(t_cub *cub, t_img *tex, int x);

void	texture_cal(t_cub *cub, int x, int side)
{
	t_img	*tex;

	tex = choose_wall(cub, side);
	if (side == 0)
		cub->tex.wall_x = cub->player.pos_y
			+ cub->player.perp_wall_dist * cub->player.ray_dir_y;
	else
		cub->tex.wall_x = cub->player.pos_x
			+ cub->player.perp_wall_dist * cub->player.ray_dir_x;
	cub->tex.wall_x -= floor(cub->tex.wall_x);
	cub->tex.tex_x = (int)(cub->tex.wall_x * (float)tex->width);
	if ((side == 0 && cub->player.ray_dir_x > 0)
		|| (side == 1 && cub->player.ray_dir_y < 0))
		cub->tex.tex_x = tex->width - cub->tex.tex_x - 1;
	cub->tex.step = 1.0f * tex->height / cub->player.line_height;
	cub->tex.draw_start = cal_range(cub, TRUE);
	cub->tex.draw_end = cal_range(cub, FALSE);
	cub->tex.tex_pos = (cub->tex.draw_start - cub->graphic.s_height / 2
			+ cub->player.line_height / 2) * cub->tex.step;
	fill_pixels(cub, tex, x);
}

static void	fill_pixels(t_cub *cub, t_img *tex, int x)
{
	int		y;
	t_hex_c	color;

	y = 0;
	while (y < cub->tex.draw_start)
	{
		set_pixel(&cub->graphic.img_screen, x, y, cub->setting.c_color);
		y++;
	}
	while (y < cub->tex.draw_end)
	{
		cub->tex.tex_y = (int)cub->tex.tex_pos & (tex->height - 1);
		cub->tex.tex_pos += cub->tex.step;
		color = get_pixel(tex, cub->tex.tex_x, cub->tex.tex_y);
		set_pixel(&cub->graphic.img_screen, x, y, color);
		y++;
	}
	while (y < cub->graphic.s_height)
	{
		set_pixel(&cub->graphic.img_screen, x, y, cub->setting.f_color);
		y++;
	}
}

static t_img	*choose_wall(t_cub *cub, int side)
{
	if (cub->player.is_door == FALSE)
	{
		if (side == 0)
		{
			if (cub->player.ray_dir_x > 0)
				return (&cub->graphic.img_e);
			else
				return (&cub->graphic.img_w);
		}
		else
		{
			if (cub->player.ray_dir_y > 0)
				return (&cub->graphic.img_s);
			else
				return (&cub->graphic.img_n);
		}
	}
	else
		return (&cub->graphic.img_door);
}
