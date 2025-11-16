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

void	check_arg(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
	{
		ft_error(ERR_ARGS);
		clean_exit_parsing(cub);
	}
	if (!av[1] || !av[1][0])
	{
		ft_error(ERR_ARGS);
		clean_exit_parsing(cub);
	}
}

void	check_cub(t_cub *cub, char *pathname)
{
	int		len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
	{
		ft_error(ERR_FILE_EXT);
		clean_exit_parsing(cub);
	}
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".cub", 4) != 0)
	{
		ft_error(ERR_FILE_EXT);
		clean_exit_parsing(cub);
	}
}

void	check_file_access(t_cub *cub, char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_error(ERR_FILE_NOT_FOUND);
		clean_exit_parsing(cub);
	}
	close(fd);
}
