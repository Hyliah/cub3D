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


char	**alloc_map_line(t_cub *cub, char **map, int *count, char *line)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (*count + 2));
	if (!new)
	{
		ft_error(ERR_MEMORY);
		ft_putstr_fd("adding new map line\n", 2);
		clean_exit_parsing(cub);
	}
	i = 0;
	while (i < *count)
	{
		new[i] = map[i];
		i++;
	}
	dup_map(cub, new, i, line);
	new[i + 1] = NULL;
	free(map);
	(*count)++;
	return (new);
}

void	dup_map(t_cub *cub, char **new, int i, char *line)
{
	new[i] = ft_strdup(line);
	if (!new[i])
	{
		while (i--)
			free(new[i]);
		free(new);
		ft_error(ERR_MEMORY);
		ft_putstr_fd("duplicating map line\n", 2);
		clean_exit_parsing(cub);
	}
}

// faire un flood fill aussi ? 
// check path ? 
