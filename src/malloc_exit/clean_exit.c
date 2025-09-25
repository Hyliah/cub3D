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

/* ca clean qued pcq ca segfault a la sortie mais c est un tomorrow me kinda problem*/

int	clean_exit(t_cub *cub)
{
	//destruction de la minimap solong type

	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.mm_f);
	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.mm_p);
	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.mm_w);

	// destruction des images des murs -> decommenter quand y aura

	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_w);
	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_e);
	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_s);
	// mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_n);
	
	//rajouter pour si portes, armes etc....

	//mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_door);
	//mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_weapon);

	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
	// ne compile pas sur mac donc mettre seulement sur le linux
	//mlx_destroy_display(cub->graphic.mlx_ptr);
	free(cub->graphic.mlx_ptr);
	cub->graphic.mlx_ptr = NULL;
	exit (EXIT_SUCCESS);
}