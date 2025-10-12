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
	//debug ------------------------------------------------------------------
	printf("NO: %s (%d)\n", cub->setting.tex_no, cub->setting.has_tex_no);
	printf("SO: %s (%d)\n", cub->setting.tex_so, cub->setting.has_tex_so);
	printf("EA: %s (%d)\n", cub->setting.tex_ea, cub->setting.has_tex_ea);
	printf("WE: %s (%d)\n", cub->setting.tex_we, cub->setting.has_tex_we);

	if (!cub->setting.has_tex_no || !cub->setting.has_tex_so
		|| !cub->setting.has_tex_ea || !cub->setting.has_tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Doesn't have texture\n", 2);
		clean_exit_parsing(cub);
		return; // 
	}
	if (!cub->setting.tex_no || !cub->setting.tex_so
		|| !cub->setting.tex_ea || !cub->setting.tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Invalid texture\n", 2);
		clean_exit_parsing(cub);
		return; // 
	}
	// check_file_access(cub, cub->setting.tex_no);
	// check_file_access(cub, cub->setting.tex_so);
	// check_file_access(cub, cub->setting.tex_ea);
	// check_file_access(cub, cub->setting.tex_we);

	// check file access one by one to identify which file has issues
	if (access(cub->setting.tex_no, F_OK | R_OK) != 0)
    {
        ft_error(ERR_MAP_INVALID);
        ft_putstr_fd("Cannot access NO texture file\n", 2);
        clean_exit_parsing(cub);
        return;
    }
    if (access(cub->setting.tex_so, F_OK | R_OK) != 0)
    {
        ft_error(ERR_MAP_INVALID);
        ft_putstr_fd("Cannot access SO texture file\n", 2);
        clean_exit_parsing(cub);
        return;
    }
    if (access(cub->setting.tex_ea, F_OK | R_OK) != 0)
    {
        ft_error(ERR_MAP_INVALID);
        ft_putstr_fd("Cannot access EA texture file\n", 2);
        clean_exit_parsing(cub);
        return;
    }
    if (access(cub->setting.tex_we, F_OK | R_OK) != 0)
    {
        ft_error(ERR_MAP_INVALID);
        ft_putstr_fd("Cannot access WE texture file\n", 2);
        clean_exit_parsing(cub);
        return;
    }
}

// check les couleurs ( entre 0 - 255) 
// apres le aprsing comnplet pour voir si tt est present et correct
// faire modif mess erreur pour couleur ? 
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
	if (cub->setting.f_color.r < 0 || cub->setting.f_color.r > 255
		|| cub->setting.f_color.g < 0 || cub->setting.f_color.g > 255
		|| cub->setting.f_color.b < 0 || cub->setting.f_color.b > 255)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid floor color: must be between 0 - 255", 2); 
		clean_exit_parsing(cub);
	}
	//ceiling
	if (cub->setting.c_color.r < 0 || cub->setting.c_color.r > 255
		|| cub->setting.c_color.g < 0 || cub->setting.c_color.g > 255
		|| cub->setting.c_color.b < 0 || cub->setting.c_color.b > 255)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid ceiling color: must be between 0 - 255", 2); 
		clean_exit_parsing(cub);
	}
}
