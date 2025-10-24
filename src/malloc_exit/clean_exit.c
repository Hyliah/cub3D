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

static void	free_t_img(t_cub *cub, t_img *img);
static void	free_after_game(t_cub *cub);

int	clean_exit(t_cub *cub)
{	
	if (cub->game_on == TRUE)
		free_after_game(cub);
	free_t_img(cub, &cub->mmap.img_mmap);
	free_t_img(cub, &cub->mmap.img_player);
	free_t_img(cub, &cub->graphic.img_e);
	free_t_img(cub, &cub->graphic.img_s);
	free_t_img(cub, &cub->graphic.img_n);
	free_t_img(cub, &cub->graphic.img_w);
	free_t_img(cub, &cub->graphic.img_screen);
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_os);
	cub->oscreen.img_os = NULL;
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_pe);
	cub->oscreen.img_pe = NULL;
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_si);
	cub->oscreen.img_si = NULL;
	free_tab(&cub->map.map_tab);
	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
	cub->graphic.win_ptr = NULL;
	// ne compile pas sur mac donc mettre seulement sur le linux
	mlx_destroy_display(cub->graphic.mlx_ptr);
	free_ptr(&cub->graphic.mlx_ptr);
	exit (EXIT_SUCCESS);
}

static void	free_t_img(t_cub *cub, t_img *img)
{
	mlx_destroy_image(cub->graphic.mlx_ptr, img->img_ptr);
	img->img_ptr = NULL;
	img->addr_ptr = NULL;
}

static void	free_after_game(t_cub *cub)
{
	free_t_img(cub, &cub->weapons.img_w1);
	free_t_img(cub, &cub->weapons.img_w2);
	free_t_img(cub, &cub->weapons.img_w3);
	free_t_img(cub, &cub->weapons.img_w4);
	free_t_img(cub, &cub->weapons.img_w5);
	free_t_img(cub, &cub->oscreen.img_olay);
}
// int	clean_exit(t_cub *cub)
// {	
// 	if (cub->game_on == TRUE)
// 	{
// 		free_t_img(cub, &cub->weapons.img_w1);
// 		free_t_img(cub, &cub->weapons.img_w2);
// 		free_t_img(cub, &cub->weapons.img_w3);
// 		free_t_img(cub, &cub->weapons.img_w4);
// 		free_t_img(cub, &cub->weapons.img_w5);
// 		free_t_img(cub, &cub->oscreen.img_olay);
// 	}
// 	free_t_img(cub, &cub->mmap.img_mmap);
// 	free_t_img(cub, &cub->mmap.img_player);
// 	free_t_img(cub, &cub->graphic.img_e);
// 	free_t_img(cub, &cub->graphic.img_s);
// 	free_t_img(cub, &cub->graphic.img_n);
// 	free_t_img(cub, &cub->graphic.img_w);
// 	free_t_img(cub, &cub->graphic.img_screen);
// 	free_img_ptr(cub, &cub->oscreen.img_os);
// 	free_img_ptr(cub, &cub->oscreen.img_pe);
// 	free_img_ptr(cub, &cub->oscreen.img_si);

// 	free_tab(&cub->map.map_tab);

// 	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
// 	cub->graphic.win_ptr = NULL;
// 	// ne compile pas sur mac donc mettre seulement sur le linux
// 	mlx_destroy_display(cub->graphic.mlx_ptr);
// 	free_ptr(&cub->graphic.mlx_ptr);
// 	exit (EXIT_SUCCESS);
// }

// static void	free_t_img(t_cub *cub, t_img *img)
// {
// 	free_img_ptr(cub, img->img_ptr);
// 	img->addr_ptr = NULL;
// }

// static void	free_img_ptr(t_cub *cub, void *img_ptr)
// {
// 	mlx_destroy_image(cub->graphic.mlx_ptr, img_ptr);
// 	img_ptr = NULL;
// }