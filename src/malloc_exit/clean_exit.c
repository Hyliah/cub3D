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

static void	free_after_game(t_cub *cub);
static void	safe_destroy_display(void **mlx_ptr);
static void	safe_destroy_window(void *mlx_ptr, void **win_ptr);

int	clean_exit(t_cub *cub)
{
	if (!cub)
		return 1;
	if (cub->game_on == TRUE)
		free_after_game(cub);
	free_t_img(cub, &cub->mmap.img_mmap);
	free_t_img(cub, &cub->mmap.img_player);
	free_t_img(cub, &cub->graphic.img_n);
	free_t_img(cub, &cub->graphic.img_s);
	free_t_img(cub, &cub->graphic.img_w);
	free_t_img(cub, &cub->graphic.img_e);
	free_t_img(cub, &cub->graphic.img_screen);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_os);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_pe);
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&cub->oscreen.img_si);
	free_tab(&cub->map.map_tab);
	free_textures(cub);
	safe_destroy_window(cub->graphic.mlx_ptr, (void **)&cub->graphic.win_ptr);
	safe_destroy_display((void **)&cub->graphic.mlx_ptr);
	free_ptr(&cub->graphic.mlx_ptr);
	exit (EXIT_SUCCESS);
}

void	free_textures(t_cub *cub)
{
	free_ptr((void **)&cub->setting.tex_no);
	free_ptr((void **)&cub->setting.tex_so);
	free_ptr((void **)&cub->setting.tex_we);
	free_ptr((void **)&cub->setting.tex_ea);
}

static void	safe_destroy_window(void *mlx_ptr, void **win_ptr)
{
	if (mlx_ptr && *win_ptr)
	{
		mlx_destroy_window(mlx_ptr, *win_ptr);
		*win_ptr = NULL;
	}
}

static void	safe_destroy_display(void **mlx_ptr)
{
	if (*mlx_ptr)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		*mlx_ptr = NULL;
	}
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





























//static void	free_after_game(t_cub *cub);


// static void	free_after_game(t_cub *cub)
// {
// 	free_t_img(cub, &cub->weapons.img_w1);
// 	free_t_img(cub, &cub->weapons.img_w2);
// 	free_t_img(cub, &cub->weapons.img_w3);
// 	free_t_img(cub, &cub->weapons.img_w4);
// 	free_t_img(cub, &cub->weapons.img_w5);
// 	free_t_img(cub, &cub->oscreen.img_olay);
// }
// int	clean_exit(t_cub *cub)
// {
// 	if (cub->game_on == TRUE)
// 		free_after_game(cub);
// 	free_t_img(cub, &cub->mmap.img_mmap);
// 	free_t_img(cub, &cub->mmap.img_player);
// 	free_t_img(cub, &cub->graphic.img_e);
// 	free_t_img(cub, &cub->graphic.img_s);
// 	free_t_img(cub, &cub->graphic.img_n);
// 	free_t_img(cub, &cub->graphic.img_w);
// 	free_t_img(cub, &cub->graphic.img_screen);
// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_os);
// 	cub->oscreen.img_os = NULL;
// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_pe);
// 	cub->oscreen.img_pe = NULL;
// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_si);
// 	cub->oscreen.img_si = NULL;
// 	free_tab(&cub->map.map_tab);
// 	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
// 	cub->graphic.win_ptr = NULL;
// 	// ne compile pas sur mac donc mettre seulement sur le linux
// 	mlx_destroy_display(cub->graphic.mlx_ptr);
// 	free_ptr(&cub->graphic.mlx_ptr);
// 	exit (EXIT_SUCCESS);
// }

// void	free_t_img(t_cub *cub, t_img *img)
// {
// 	mlx_destroy_image(cub->graphic.mlx_ptr, img->img_ptr);
// 	img->img_ptr = NULL;
// 	img->addr_ptr = NULL;
// }





























// static void	free_after_game(t_cub *cub);
// //static void	safe_destroy_image(void *mlx_ptr, void **img_ptr);

// int	clean_exit(t_cub *cub)
// {
// 	if (cub->game_on == TRUE)
// 		// 	free_t_img(cub, &cub->weapons.img_w1);
		// 	free_t_img(cub, &cub->weapons.img_w2);
		// 	free_t_img(cub, &cub->weapons.img_w3);
		// 	free_t_img(cub, &cub->weapons.img_w4);
		// 	free_t_img(cub, &cub->weapons.img_w5);
		// 	free_t_img(cub, &cub->oscreen.img_olay);

// 	free_t_img(cub, &cub->mmap.img_mmap);
// 	free_t_img(cub, &cub->mmap.img_player);
// 	free_t_img(cub, &cub->graphic.img_e);
// 	free_t_img(cub, &cub->graphic.img_s);
// 	free_t_img(cub, &cub->graphic.img_n);
// 	free_t_img(cub, &cub->graphic.img_w);
// 	free_t_img(cub, &cub->graphic.img_screen);

// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_os);
// 	cub->oscreen.img_os = NULL;
// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_pe);
// 	cub->oscreen.img_pe = NULL;
// 	mlx_destroy_image(cub->graphic.mlx_ptr, cub->oscreen.img_si);
// 	cub->oscreen.img_si = NULL;

// 	free_tab(&cub->map.map_tab);
// 	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);

// 	cub->graphic.win_ptr = NULL;

// 	// ne compile pas sur mac donc mettre seulement sur le linux
// 	mlx_destroy_display(cub->graphic.mlx_ptr);
// 	
// free_ptr(&cub->graphic.mlx_ptr);
// 	free_textures(cub);
// 	exit (EXIT_SUCCESS);
// }

// // void	free_t_img(t_cub *cub, t_img *img)
// // {
// // 	if (img && img->img_ptr)
// // 	{
// // 		mlx_destroy_image(cub->graphic.mlx_ptr, img->img_ptr);
// // 		img->img_ptr = NULL;
// // 		img->addr_ptr = NULL;
// // 	}
// // }






