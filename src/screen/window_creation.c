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

static void init_buffer(t_cub *cub, int x, int y);

void	create_window(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->graphic.s_width;
	y = cub->graphic.s_height;
	cub->graphic.mlx_ptr = mlx_init();
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr, x, y, G_NAME);
	init_buffer(cub, x, y);
	cub->graphic.img = mlx_new_image(cub->graphic.mlx_ptr, x, y);
	cub->graphic.addr = mlx_get_data_addr(cub->graphic.img, &cub->graphic.bpp,
										  &cub->graphic.size_line,
										  &cub->graphic.endian);
	mlx_hook(cub->graphic.win_ptr, 17, 0, clean_exit, cub);
}

/* 
	mlx differente sur mac et linux, creation d un buffer maison pour mac 
*/

#ifdef __APPLE__
static void init_buffer(t_cub *cub, int x, int y)
{
	cub->graphic.buffer = malloc(sizeof(unsigned int) * x * y);
	if (!cub->graphic.buffer)
	{
		perror("malloc buffer");
		exit(1);
	}
	ft_memset(cub->graphic.buffer, 0, sizeof(unsigned int) * x * y);
}
#else
static void init_buffer(t_cub *cub, int x, int y)
{
	(void)cub;
	(void)x;
	(void)y;
}
#endif

// void	create_image_test(t_cub *cub)
// {
// 	cub->graphic.img_co = mlx_xpm_file_to_image(graphic->mlx_ptr, CO, &x, &y);
// }