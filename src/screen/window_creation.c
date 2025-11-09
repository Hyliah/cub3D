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

static void	game_on(t_cub *cub);
static void	mm_size_calculator(t_cub *cub);
static int	init_img(t_cub *cub, t_img *img, t_bool minimap);

int	create_window(t_cub *cub)
{
	cub->graphic.mlx_ptr = mlx_init();
	if (!cub->graphic.mlx_ptr)
		return (clean_exit(cub), 1);
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr,
			cub->graphic.s_width, cub->graphic.s_height, G_NAME);
	if (!cub->graphic.win_ptr)
		return (clean_exit(cub), 1);
	mm_size_calculator(cub);
	if (init_opening_screen(cub))
		return (1);
	if (init_walls(cub))
		return (1);
	if (init_img(cub, &cub->graphic.img_screen, FALSE))
		return (1);
	if (init_img(cub, &cub->mmap.img_mmap, TRUE))
		return (1);
	if (init_img(cub, &cub->mmap.img_player, TRUE))
		return (1);
	game_on(cub);
	return (0);
}

static int	init_img(t_cub *cub, t_img *img, t_bool minimap)
{
	int	x;
	int	y;

	if (minimap)
	{
		x = cub->mmap.mm_wid;
		y = cub->mmap.mm_hei;
	}
	else
	{
		x = cub->graphic.s_width;
		y = cub->graphic.s_height;
	}
	img->img_ptr = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	if (!img->img_ptr)
		return (clean_exit(cub), 1);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
	return (0);
}

//calcul pour connaitre le ration map/scren/minimap 
//-> donne un square qui correspond a la taille d une unite sur la minimap
static void	mm_size_calculator(t_cub *cub)
{
	int	mm_ratio;

	mm_ratio = cub->map.width / cub->map.height;
	if (mm_ratio > 1)
	{
		cub->mmap.mm_wid = MM_MAX_W;
		cub->mmap.mm_hei = MM_MAX_W / mm_ratio;
	}
	else
	{
		cub->mmap.mm_hei = MM_MAX_H;
		cub->mmap.mm_wid = MM_MAX_H * mm_ratio;
	}
	cub->mmap.mm_sqr = cub->mmap.mm_wid / cub->map.width;
}

static void	game_on(t_cub *cub)
{
	mm_creation(cub);
	while (cub->game_on == TRUE)
		raycasting(cub);
	mlx_hook(cub->graphic.win_ptr, 17, 0, clean_exit, cub);
}
