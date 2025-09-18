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

void	create_window(t_cub *cub)
{
	int	x;
	int	y;

	// taille pour mac at home
	x = 960; // completement a choix, c est la taille de la window
	y = 540; 

	// taille pour linux
	// x = 1920; // completement a choix, c est la taille de la window
	// y = 1080; 

	cub->graphic.mlx_ptr = mlx_init();
	cub->graphic.win_ptr = mlx_new_window(cub->graphic.mlx_ptr, x, y, G_NAME);
	//mlx_get_Screen ou qqc cmme ca -> mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
	// creer un ecran
}

// void	create_image_test(t_cub *cub)
// {
// 	cub->graphic.img_co = mlx_xpm_file_to_image(graphic->mlx_ptr, CO, &x, &y);
// }