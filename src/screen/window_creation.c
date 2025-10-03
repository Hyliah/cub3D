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


static void	init_img(t_cub *cub, t_img *img, int x, int y);
static void	mm_size_calculator(t_cub *cub);

void	create_window(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	cub->graphic.mlx_ptr = mlx_init();
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr, x, y, G_NAME);
	mm_size_calculator(cub);
	init_img(cub, &cub->graphic.img_screen, x, y);
	init_img(cub, &cub->mmap.img_mmap, cub->mmap.mm_wid, cub->mmap.mm_hei);
	init_img(cub, &cub->mmap.img_player, cub->mmap.mm_wid, cub->mmap.mm_hei);
	mm_creation(cub);
	mlx_hook(cub->graphic.win_ptr, 17, 0, clean_exit, cub);
}

static void	init_img(t_cub *cub, t_img *img, int x, int y)
{
	img->img_ptr = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, 
					&img->endian);
}

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

/* 
	mlx differente sur mac et linux, creation d un buffer maison pour mac 
*/


// #ifdef __APPLE__
// static void init_buffer(t_cub *cub, int x, int y);
// static void init_buffer(t_cub *cub, int x, int y)
// {
// 	cub->graphic.buffer = malloc(sizeof(unsigned int) * x * y);
// 	if (!cub->graphic.buffer)
// 	{
// 		perror("malloc buffer");
// 		exit(1);
// 	}
// 	ft_memset(cub->graphic.buffer, 0, sizeof(unsigned int) * x * y);
// }
// #else
// static void init_buffer(t_cub *cub, int x, int y)
// {
// 	(void)cub;
// 	(void)x;
// 	(void)y;
// }
// #endif

// void	create_image_test(t_cub *cub)
// {
// 	cub->graphic.img_co = mlx_xpm_file_to_image(graphic->mlx_ptr, CO, &x, &y);
// }

