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

// parsing de la ligne de texture : "NO ./path/to/texture.xpm"
void	parse_texture_line(t_cub *cub, char *line)
{
	char	**split;
	char	*orientation;
	char	*path;

	split = ft_split(line, ' '); // on split les 2 element : orientation et chemin de la texture
	if (!split || !split[0] || !split[1])
	{
		free_tab(split);
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing(cub);
	}
	orientation = split[0];
	path = split[1];
	if (ft_strncmp(orientation, "NO", 3) == 0)
		parse_text_no(cub, path);
	else if (ft_strncmp(orientation, "SO", 3) == 0)
		parse_text_so(cub, path);
	else if (ft_strncmp(orientation, "EA", 3) == 0)
		parse_text_ea(cub, path);
	else if (ft_strncmp(orientation, "WE", 3) == 0)
		parse_text_we(cub, path);
	else
	{
		free_tab(split);
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici ( invalid texture orientation)
		clean_exit_parsing;
	}
	free_tab(split);
}

void	parse_text_no(t_cub *cub, char *path)
{
	if (cub->setting.has_tex_no)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( texture already defined ? )
		clean_exit_parsing;
	}
	cub->setting.tex_no = ft_strdup(path);
	if (!cub->setting.tex_no)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( memory failed for NO texture )
		clean_exit_parsing;
	}
	cub->setting.has_tex_no = 1;
}

void	parse_text_so(t_cub *cub, char *path)
{
	if (cub->setting.has_tex_so)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( texture already defined ? )
		clean_exit_parsing;
	}
	cub->setting.tex_so = ft_strdup(path);
	if (!cub->setting.tex_so)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( memory failed for SO texture )
		clean_exit_parsing;
	}
	cub->setting.has_tex_so = 1;
}

void	parse_text_ea(t_cub *cub, char *path)
{
	if (cub->setting.has_tex_ea)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( texture already defined ? )
		clean_exit_parsing;
	}
	cub->setting.tex_ea = ft_strdup(path);
	if (!cub->setting.tex_ea)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( memory failed for EA texture )
		clean_exit_parsing;
	}
	cub->setting.has_tex_so = 1;
}

void	parse_text_we(t_cub *cub, char *path)
{
	if (cub->setting.has_tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( texture already defined ? )
		clean_exit_parsing;
	}
	cub->setting.tex_we = ft_strdup(path);
	if (!cub->setting.tex_we)
	{
		ft_error(ERR_MAP_INVALID);
		// mess plus explicite ici aussi ? ( memory failed for SO texture )
		clean_exit_parsing;
	}
	cub->setting.has_tex_we = 1;
}