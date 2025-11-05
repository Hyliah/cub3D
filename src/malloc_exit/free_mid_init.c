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

static void	free_mid_init_1(t_cub *cub, int exit_nb);
static void	free_mid_init_2(t_cub *cub, int exit_nb);

void	free_mid_init(t_cub *cub, int exit_nb)
{
	free_mid_init_1(cub, exit_nb);
	free_mid_init_2(cub, exit_nb);
	if (exit_nb <= 12)
		free_t_img(cub, &cub->weapons.img_w1);
	if (exit_nb <= 13)
		free_t_img(cub, &cub->graphic.img_e);
	if (exit_nb <= 14)
		free_t_img(cub, &cub->graphic.img_e);
	if (exit_nb <= 15)
		free_t_img(cub, &cub->graphic.img_e);
	if (exit_nb <= 16)
		free_t_img(cub, &cub->graphic.img_e);
	if (exit_nb <= 17)
		free_t_img(cub, &cub->graphic.img_screen);
	if (exit_nb <= 18)
		free_t_img(cub, &cub->mmap.img_mmap);
	if (exit_nb <= 19)
		free_t_img(cub, &cub->mmap.img_player);
}

static void	free_mid_init_1(t_cub *cub, int exit_nb)
{
	if (exit_nb <= 1)
		free_tab(&cub->map.map_tab);
	if (exit_nb <= 2)
	{
		mlx_destroy_display(cub->graphic.mlx_ptr);
		free_ptr(&cub->graphic.mlx_ptr);
	}
	if (exit_nb <= 3)
	{
		mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
		cub->graphic.win_ptr = NULL;
	}
	if (exit_nb <= 4)
	{
		mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_os);
		cub->oscreen.img_os = NULL;
	}
	if (exit_nb <= 5)
	{
		mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_pe);
		cub->oscreen.img_pe = NULL;
	}
}

static void	free_mid_init_2(t_cub *cub, int exit_nb)
{
	if (exit_nb <= 6)
	{
		mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_si);
		cub->oscreen.img_si = NULL;
	}
	if (exit_nb <= 7)
		free_t_img(cub, &cub->oscreen.img_olay);
	if (exit_nb <= 8)
		free_t_img(cub, &cub->weapons.img_w1);
	if (exit_nb <= 9)
		free_t_img(cub, &cub->weapons.img_w2);
	if (exit_nb <= 10)
		free_t_img(cub, &cub->weapons.img_w3);
	if (exit_nb <= 11)
		free_t_img(cub, &cub->weapons.img_w4);
}
