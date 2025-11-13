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

void	ft_strtrim_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	ft_strtrim_spaces(char *s)
{
	char	*dst;

	dst = s;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			*dst++ = *s;
		s++;
	}
	*dst = '\0';
}

int	open_cub_file(t_cub *cub, char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_error(ERR_FILE_NOT_FOUND);
		clean_exit_parsing(cub);
	}
	return (fd);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_rgb_component_length(t_cub *cub, char *comp, char **rgb)
{
	int	len;

	len = ft_strlen(comp);
	if (len > 3)
	{
		ft_error(ERR_COLOR);
		ft_putstr_fd("RGB component too long (max 3 digits per value)\n", 2);
		free_tab(&rgb);
		clean_exit_parsing(cub);
	}
}
