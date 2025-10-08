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
static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y);

void	merge_screens(t_cub *cub)
{
	clear_image(cub);

	if (cub->mmap.mm_show == TRUE)
	{
		int mmap_x;
		int mmap_y;

		// déclaration des offsets -> modifiable
		mmap_x = cub->graphic.s_width - cub->mmap.mm_wid - 20; // map + 20px depuis le bord droit
		mmap_y = 20; // a 20 de hauteur depuis le bord
		// mmap_x = cub->graphic.s_width - cub->mmap.mm_wid;
		// mmap_y = 0; // a 20 de hauteur depuis le bord

		// au cas ou
		// draw_mmap_border mmap_x - 1 &&  mmap_y - 1;

		merge_screen(cub, &cub->mmap.img_mmap, mmap_x, mmap_y);
		merge_screen(cub, &cub->mmap.img_player, mmap_x, mmap_y);
	}

	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr,
							cub->graphic.img_screen.img_ptr, 0, 0);
}

static void clear_image(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub->mmap.mm_wid)
	{
		i = 0;
		while (i < cub->mmap.mm_hei)
		{
			set_pixel(&cub->graphic.img_screen, i, j, 0x000000); // ou ecrire 0 mais c est plus clair pour moi atm
			i++;
		}
		j++;
	}
}

static void	merge_screen(t_cub *cub, t_img *img, int offset_x, int offset_y)
{
	int		x;
	int		y;
	t_hex_c	pixel_color;

	y = 0;
	while (y < cub->mmap.mm_hei && (y + offset_y) < cub->graphic.s_height)
	{
		x = 0;
		while (x < cub->mmap.mm_wid && (x + offset_x) < cub->graphic.s_width)
		{
			pixel_color = get_pixel(img, x, y);
			if (pixel_color != 0x000000)
				set_pixel(&cub->graphic.img_screen, x + offset_x, y + offset_y, pixel_color);
			x++;
		}
		y++;
	}
}



// void merge_screens(t_cub *cub)
// {
// 	clear_image(cub);

// 	merge_screen(cub, &cub->mmap.img_mmap);
// 	merge_screen(cub, &cub->mmap.img_player);
// 	mlx_put_image_to_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr, &cub->graphic.img_screen.img_ptr, 0, 0);
// }


// static void merge_screen(t_cub *cub, t_img *img)
// {
// 	int	x;
// 	int	y;
// 	t_hex_c	pixel_color;
	
// 	y = 0;
// 	while (y < cub->mmap.mm_hei)
// 	{
// 		x = 0;
// 		while (x < cub->mmap.mm_wid)
// 		{
// 			pixel_color = get_pixel(img, x, y);
// 			// if( pixel_color != 0)
// 			// 	printf("new_color = %u\n", pixel_color);
// 			if (pixel_color != 0x000000)
// 				set_pixel(&cub->graphic.img_screen, x, y, pixel_color);
// 			x++;
// 		}
// 		y++;
// 	}
// }