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

// check que tt a bine ete trouve et parse 

// check presence de toutes les textures NO, SO, WE, EA
void	check_texture(t_cub *cub)
{
	if (!cub->setting.has_tex_no || !cub->setting.has_tex_so
		|| !cub->setting.has_tex_ea || !cub->setting.has_tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Doesn't have texture\n", 2);
		clean_exit_parsing(cub);
	}
	if (!cub->setting.tex_no || !cub->setting.tex_so
		|| !cub->setting.tex_ea || !cub->setting.tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Invalid texture\n", 2);
		clean_exit_parsing(cub);
	}
	check_file_access(cub, cub->setting.has_tex_no);
	check_file_access(cub, cub->setting.has_tex_so);
	check_file_access(cub, cub->setting.has_tex_ea);
	check_file_access(cub, cub->setting.has_tex_we);
}

// check les couleurs ( entre 0 - 255) // faire modif mess erreur pour couleur ? 
void	check_color(t_cub *cub)
{
	// flag
	if (!cub->setting.has_ceiling || !cub->setting.has_floor)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Doesn't have ceiling / floor\n", 2);
		clean_exit_parsing(cub);
	}
	// floor
	if (!cub->setting.f_color.r < 0 || !cub->setting.f_color.r > 255
		|| !cub->setting.f_color.g < 0 || !cub->setting.f_color.g > 255
		|| !cub->setting.f_color.b < 0 || !cub->setting.f_color.b > 255)
	{
		ft_error(ERR_COLOR);
		clean_exit_parsing(cub);
	}
	//ceiling
	if (!cub->setting.c_color.r < 0 || !cub->setting.c_color.r > 255
		|| !cub->setting.c_color.g < 0 || !cub->setting.c_color.g > 255
		|| !cub->setting.c_color.b < 0 || !cub->setting.c_color.b > 255)
	{
		ft_error(ERR_COLOR);
		clean_exit_parsing(cub);
	}
}
