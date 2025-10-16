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

	//printf("DEBUG: parse_texture_line -> '%s'\n", line); // DEBUG : ligne reçue -----------------------------------

	if (!line || !*line)
	{
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Empty texture line\n", 2);
		clean_exit_parsing(cub);
	}

	split = ft_split(line, ' '); // on split les 2 element : orientation et chemin de la texture
	if (!split || !split[0] || !split[1] || split[2])
	{
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Invalid texture format\n", 2);
		clean_exit_parsing(cub);
	}
	orientation = split[0];
	path = split[1];

	// printf("DEBUG: orientation='%s', path='%s'\n", orientation, path); // -----------------------------------

	//verif xpm
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
		free_tab(&split);
		ft_error(ERR_TEXTURE);
		ft_putstr_fd("Invalid texture orientation\n", 2);
		clean_exit_parsing(cub);
	}
	free_tab(&split);

	// DEBUG : afficher l’état après parse -----------------------------------
	// printf("DEBUG: has_tex_no=%d, has_tex_so=%d, has_tex_ea=%d, has_tex_we=%d\n",
	// 	cub->setting.has_tex_no,
	// 	cub->setting.has_tex_so,
	// 	cub->setting.has_tex_ea,
	// 	cub->setting.has_tex_we);
	// printf("DEBUG: tex_no=%p, tex_so=%p, tex_ea=%p, tex_we=%p\n",
	// 	cub->setting.tex_no,
	// 	cub->setting.tex_so,
	// 	cub->setting.tex_ea,
	// 	cub->setting.tex_we);
}

void	parse_text_no(t_cub *cub, char *path)
{
	//printf("DEBUG: parse_text_no path='%s'\n", path);
	if (cub->setting.has_tex_no)
	{
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

void	parse_text_so(t_cub *cub, char *path)
{
	//printf("DEBUG: parse_text_so path='%s'\n", path);
	if (cub->setting.has_tex_so)
	{
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

void	parse_text_ea(t_cub *cub, char *path)
{
	//printf("DEBUG: parse_text_ea path='%s'\n", path);
	if (cub->setting.has_tex_ea)
	{
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

void	parse_text_we(t_cub *cub, char *path)
{
	//printf("DEBUG: parse_text_we path='%s'\n", path);
	if (cub->setting.has_tex_we)
	{
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