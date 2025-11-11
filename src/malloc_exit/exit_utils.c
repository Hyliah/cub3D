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

int	clean_exit_parsing(t_cub *cub)
{
	if (cub->map.current_line)
	{
		free(cub->map.current_line);
		cub->map.current_line = NULL;
	}
	if (!cub)
		exit(EXIT_FAILURE);
	if (cub->setting.fd > 2)
	{
		close(cub->setting.fd);
		cub->setting.fd = -1;
	}
	free_textures(cub);
	free_map(cub);
	cub->map.map_start = 0;
	exit(EXIT_FAILURE);
}

void	free_t_img(t_cub *cub, t_img *img)
{
	if (!cub || !img)
		return ;
	safe_destroy_image(cub->graphic.mlx_ptr, (void **)&img->img_ptr);
	img->addr_ptr = NULL;
}

void	safe_destroy_image(void *mlx_ptr, void **img_ptr)
{
	if (mlx_ptr && *img_ptr)
	{
		mlx_destroy_image(mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
}
