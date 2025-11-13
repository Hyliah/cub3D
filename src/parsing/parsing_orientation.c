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

void	parse_text_no(t_cub *cub, char *path, char **split)
{
	if (cub->setting.has_tex_no)
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Texture NO already defined\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.tex_no = ft_strdup(path);
	if (!cub->setting.tex_no)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Memory failed for NO texture\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.has_tex_no = 1;
}

void	parse_text_so(t_cub *cub, char *path, char **split)
{
	if (cub->setting.has_tex_so)
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Texture SO already defined\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.tex_so = ft_strdup(path);
	if (!cub->setting.tex_so)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Memory failed for SO texture\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.has_tex_so = 1;
}

void	parse_text_ea(t_cub *cub, char *path, char **split)
{
	if (cub->setting.has_tex_ea)
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Texture EA already defined\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.tex_ea = ft_strdup(path);
	if (!cub->setting.tex_ea)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Memory failed for EA texture\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.has_tex_ea = 1;
}

void	parse_text_we(t_cub *cub, char *path, char **split)
{
	if (cub->setting.has_tex_we)
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Texture WE already defined\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.tex_we = ft_strdup(path);
	if (!cub->setting.tex_we)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Memory failed for WE texture\n", 2);
		clean_exit_parsing(cub);
	}
	cub->setting.has_tex_we = 1;
}

void	check_duplicate_texture(t_cub *cub)
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;

	no = cub->setting.tex_no;
	so = cub->setting.tex_so;
	ea = cub->setting.tex_ea;
	we = cub->setting.tex_we;
	if (ft_strcmp(no, so) == 0 || ft_strcmp(no, ea) == 0
		|| ft_strcmp(no, we) == 0 || ft_strcmp(so, ea) == 0
		|| ft_strcmp(so, we) == 0 || ft_strcmp(ea, we) == 0)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Duplicate texture file ", 2);
		ft_putstr_fd("(NO/SO/EA/WE must be different)\n", 2);
		clean_exit_parsing(cub);
	}
}
