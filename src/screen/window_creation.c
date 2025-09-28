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

/* taille de la minimap a gerermais /8 c est deja pas mal*/
void	create_window(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	cub->graphic.mlx_ptr = mlx_init();
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr, x, y, G_NAME);
	init_img(cub, &cub->graphic.screen, x, y);
	init_img(cub, &cub->mmap.minimap, cub->mmap.mm_width, cub->mmap.mm_height);
	draw_minimap(cub);
	mlx_hook(cub->graphic.win_ptr, 17, 0, clean_exit, cub);
}

static void	init_img(t_cub *cub, t_img *img, int x, int y)
{
	img->img_ptr = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	img->addr_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, 
					&img->endian);
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

