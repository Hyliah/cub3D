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

// alloc du tableau de ligen de la map 
char	**alloc_map_line(t_cub *cub, char **map, int *count, char *line)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (*count + 2));
	if (!new)
	{
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing(cub);
	}
	i = 0;
	while (i < *count)
	{
		new[i] = map[i];
		i++;
	}
	new[i] = ft_strdup(line);
	if (!new[i])
	{
		while (i--)
			free(new[i]);
		free(new);
		ft_error(ERR_MAP_INVALID);
		clean_exit_parsing(cub);
	}
	new[i + 1] = NULL;
	free(map);
	(*count)++;
	return (new);
}

// faire un flood fill aussi ? 
// check path ? 
// lignes vides avant et apres la map mais pas au milieu 

// faire des messages d’erreur pour chaque cas et quitter de maniere clean