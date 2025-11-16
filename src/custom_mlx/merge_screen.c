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

static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y);

void	merge_screens(t_cub *cub)
{
	int	mmap_x;
	int	mmap_y;

	if (cub->game_on == TRUE)
		raycasting(cub);
	if (cub->mmap.mm_show == TRUE)
	{
		mmap_x = cub->graphic.s_width - cub->mmap.mm_wid - 20;
		mmap_y = 20;
		merge_screen(cub, &cub->mmap.img_mmap, mmap_x, mmap_y);
		merge_screen(cub, &cub->mmap.img_player, mmap_x, mmap_y);
	}
	merge_screen(cub, move_weapon(cub), 0, 0);
	merge_screen(cub, &cub->oscreen.img_olay, 0, 0);
	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
		cub->graphic.img_screen.img_ptr, 0, 0);
}

static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y)
{
	int		x;
	int		y;
	t_hex_c	pixel_color;

	y = 0;
	while (y < img->height && (y + offset_y) < cub->graphic.s_height)
	{
		x = 0;
		while (x < img->width && (x + offset_x) < cub->graphic.s_width)
		{
			pixel_color = get_pixel(img, x, y);
			if (pixel_color != 0x000000)
				set_pixel(&cub->graphic.img_screen, x + offset_x, y + offset_y,
					pixel_color);
			x++;
		}
		y++;
	}
}
