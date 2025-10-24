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
static void	init_img(t_cub *cub, t_img *img, int x, int y);

void	create_window(t_cub *cub)
{
	int	x;
	int	y;
	int	ret;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	cub->graphic.mlx_ptr = mlx_init();
	if (!cub->graphic.mlx_ptr)
		return (free_mid_init(cub, 1), NULL);
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr, x, y, G_NAME);
	if (!cub->graphic.win_ptr)
		return (free_mid_init(cub, 2), NULL);
	mm_size_calculator(cub);
	init_opening_screen(cub);
	init_walls(cub);
	init_img(cub, &cub->graphic.img_screen, x, y);
	if (!&cub->graphic.img_screen)
		return (free_mid_init(cub, 8), NULL);
	init_img(cub, &cub->mmap.img_mmap, cub->mmap.mm_wid, cub->mmap.mm_hei);
	if (!&cub->mmap.img_mmap)
		return (free_mid_init(cub, 9), NULL);
	init_img(cub, &cub->mmap.img_player, cub->mmap.mm_wid, cub->mmap.mm_hei);
	if (!&cub->mmap.img_player)
		return (free_mid_init(cub, 10), NULL);
	game_on(cub);
}

static void	init_img(t_cub *cub, t_img *img, int x, int y)
{
	img->img_ptr = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->width = x;
	img->height = y;
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