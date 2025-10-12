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

// seulement apres init mlx 
int	clean_exit(t_cub *cub)
{
	// destruction des images des murs
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_w);
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_e);
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_s);
	mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_n);
	//rajouter pour si portes, armes etc....
	//mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_door);
	//mlx_destroy_image(cub->graphic.mlx_ptr, cub->graphic.img_weapon);

	mlx_destroy_window(cub->graphic.mlx_ptr, cub->graphic.win_ptr);
	mlx_destroy_display(cub->graphic.mlx_ptr);
	free(cub->graphic.mlx_ptr);
	cub->graphic.mlx_ptr = NULL;
	exit (EXIT_SUCCESS);
}

// separer en deux fonctions 
// car si on appelle des le parsing MLX pas init donc va crasher 

int	clean_exit_parsing(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);

	if (cub->setting.fd > 2) 
	{// fd == 0 (stdin) ou fd == 1/2 (stdout/stderr) ne doivent jamais être fermés. ?? a check 
		close(cub->setting.fd);
		cub->setting.fd = -1;
	}
	// free texture de tout et remise a NULL
	if (cub->setting.tex_no)
    {
        free(cub->setting.tex_no);
        cub->setting.tex_no = NULL;
    }
    if (cub->setting.tex_so)
    {
        free(cub->setting.tex_so);
        cub->setting.tex_so = NULL;
    }
    if (cub->setting.tex_ea)
    {
        free(cub->setting.tex_ea);
        cub->setting.tex_ea = NULL;
    }
    if (cub->setting.tex_we)
    {
        free(cub->setting.tex_we);
        cub->setting.tex_we = NULL;
    }
	// free la map
	if(cub->map.map_tab)
	{
		free_tab(&cub->map.map_tab);
		cub->map.map_tab = NULL;
	}
	free(cub);
	exit (EXIT_FAILURE);
}
