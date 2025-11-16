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

static int	init_ol_sirius(t_cub *cub);
static int	init_ol_pepito(t_cub *cub);
static int	init_overlays(t_cub *cub, t_img *img, char *xpm);

int	init_overlays_weapons(t_cub *cub)
{
	if (cub->oscreen.is_sirius == TRUE)
	{
		if (init_ol_sirius(cub))
			return (1);
	}
	else
	{
		if (init_ol_pepito(cub))
			return (1);
	}
	return (0);
}

static int	init_ol_sirius(t_cub *cub)
{
	if (init_overlays(cub, &cub->oscreen.img_olay, OVRLS))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w1, W1S))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w2, W2S))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w3, W3S))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w4, W4S))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w5, W5S))
		return (1);
	return (0);
}

static int	init_ol_pepito(t_cub *cub)
{
	if (init_overlays(cub, &cub->oscreen.img_olay, OVRLP))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w1, W1P))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w2, W2P))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w3, W3P))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w4, W4P))
		return (1);
	if (init_overlays(cub, &cub->weapons.img_w5, W5P))
		return (1);
	return (0);
}

static int	init_overlays(t_cub *cub, t_img *img, char *xpm)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	img->img_ptr = mlx_xpm_file_to_image(cub->graphic.mlx_ptr, xpm, &x, &y);
	if (!img->img_ptr)
		return (clean_exit(cub), 1);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
	return (0);
}
