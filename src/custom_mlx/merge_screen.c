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

static void clear_image(t_cub *cub);
static void merge_screen(t_cub *cub, t_img *img);

void merge_screens(t_cub *cub)
{
	clear_image(cub);

	merge_screen(cub, &cub->mmap.img_mmap);
	merge_screen(cub, &cub->mmap.img_player);
	puts("there");
	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, &cub->graphic.img_screen, 0, 0);
}

static void clear_image(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->mmap.mm_wid)
	{
		j = 0;
		while (j < cub->mmap.mm_hei)
		{
			set_pixel(&cub->graphic.img_screen, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

static void merge_screen(t_cub *cub, t_img *img)
{
	int	x;
	int	y;
	t_hex_c	pixel_color;

	puts("here");
	y = 0;
	while (y < cub->mmap.mm_wid)
	{
		x = 0;
		while (x < cub->mmap.mm_hei)
		{
			pixel_color = get_pixel(img, x, y);
			if (pixel_color != 0x000000)
				set_pixel(&cub->graphic.img_screen, x, y, pixel_color);
			x++;
		}
		y++;
	}
}
