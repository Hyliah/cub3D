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

void	check_texture(t_cub *cub)
{
	if (!cub->setting.has_tex_no || !cub->setting.has_tex_so
		|| !cub->setting.has_tex_ea || !cub->setting.has_tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Missing texture identifier (NO/SO/WE/EA)\n", 2);
		clean_exit_parsing(cub);
	}
	if (!cub->setting.tex_no || !cub->setting.tex_so
		|| !cub->setting.tex_ea || !cub->setting.tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("One or more texture paths are NULL\n", 2);
		if (!cub->setting.tex_no)
			ft_putstr_fd("tex_no is NULL\n", 2);
		if (!cub->setting.tex_so)
			ft_putstr_fd("tex_so is NULL\n", 2);
		if (!cub->setting.tex_we)
			ft_putstr_fd("tex_we is NULL\n", 2);
		if (!cub->setting.tex_ea)
			ft_putstr_fd("tex_ea is NULL\n", 2);
		clean_exit_parsing(cub);
	}
	check_access_texture(cub);
	check_duplicate_texture(cub);
}

void	check_access_texture(t_cub *cub)
{
	check_file_access(cub, cub->setting.tex_no);
	check_file_access(cub, cub->setting.tex_so);
	check_file_access(cub, cub->setting.tex_ea);
	check_file_access(cub, cub->setting.tex_we);
}

void	check_color(t_cub *cub)
{
	if (!cub->setting.has_ceiling || !cub->setting.has_floor)
	{
		ft_error(ERR_MAP_INVALID);
		ft_putstr_fd("Doesn't have ceiling / floor\n", 2);
		clean_exit_parsing(cub);
	}
	if (cub->setting.rgb_f_color.r < 0 || cub->setting.rgb_f_color.r > 255
		|| cub->setting.rgb_f_color.g < 0 || cub->setting.rgb_f_color.g > 255
		|| cub->setting.rgb_f_color.b < 0 || cub->setting.rgb_f_color.b > 255)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid floor color: must be between 0 - 255", 2);
		clean_exit_parsing(cub);
	}
	if (cub->setting.rgb_c_color.r < 0 || cub->setting.rgb_c_color.r > 255
		|| cub->setting.rgb_c_color.g < 0 || cub->setting.rgb_c_color.g > 255
		|| cub->setting.rgb_c_color.b < 0 || cub->setting.rgb_c_color.b > 255)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("Invalid ceiling color: must be between 0 - 255", 2);
		clean_exit_parsing(cub);
	}
}
