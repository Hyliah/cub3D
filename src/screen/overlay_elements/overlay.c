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

static void	init_overlays(t_cub *cub, t_img *img, char *xpm);

int	init_overlays_weapons(t_cub *cub)
{
	if (cub->oscreen.is_sirius == TRUE)
	{
		init_overlays(cub, &cub->oscreen.img_olay, OVRLS);
		if (!&cub->oscreen.img_olay)
			return (free_mid_init(cub, 6), 1);
		init_overlays(cub, &cub->weapons.img_w1, W1S);
		if (!&cub->weapons.img_w1)
			return (free_mid_init(cub, 7), 1);
		init_overlays(cub, &cub->weapons.img_w2, W2S);
		if (!&cub->weapons.img_w2)
			return (free_mid_init(cub, 8), 1);
		init_overlays(cub, &cub->weapons.img_w3, W3S);
		if (!&cub->weapons.img_w3)
			return (free_mid_init(cub, 9), 1);
		init_overlays(cub, &cub->weapons.img_w4, W4S);
		if (!&cub->weapons.img_w4)
			return (free_mid_init(cub, 10), 1);
		init_overlays(cub, &cub->weapons.img_w5, W5S);
		if (!&cub->weapons.img_w5)
			return (free_mid_init(cub, 10), 1);
	}
	else
	{
		init_overlays(cub, &cub->oscreen.img_olay, OVRLP);
		init_overlays(cub, &cub->weapons.img_w1, W1P);
		init_overlays(cub, &cub->weapons.img_w2, W2P);
		init_overlays(cub, &cub->weapons.img_w3, W3P);
		init_overlays(cub, &cub->weapons.img_w4, W4P);
		init_overlays(cub, &cub->weapons.img_w5, W5P);
	}
}

static void	init_overlays(t_cub *cub, t_img *img, char *xpm)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	// if (!img->img_ptr)
	// 	infructuous_smth;
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
}
