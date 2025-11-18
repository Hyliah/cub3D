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

static void	copy_row(char *dest, const char *src, int width);
static char	**alloc_cpy_tab(t_cub *cub);

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

char	**cpy_map(t_cub *cub)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = alloc_cpy_tab(cub);
	if (!cpy)
		return (NULL);
	while (i < cub->map.height)
	{
		copy_row(cpy[i], cub->map.map_tab[i], cub->map.width);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static char	**alloc_cpy_tab(t_cub *cub)
{
	int		i;
	char	**cpy;

	cpy = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < cub->map.height)
	{
		cpy[i] = malloc(cub->map.width + 1);
		if (cpy[i] == NULL)
			return (free_mid_tab(cub, &cpy, i), NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static void	copy_row(char *dest, const char *src, int width)
{
	size_t	src_len;
	int		j;

	src_len = ft_strlen(src);
	j = 0;
	while (j < width)
	{
		if ((size_t)j < src_len)
			dest[j] = src[j];
		else
			dest[j] = ' ';
		j++;
	}
	dest[j] = '\0';
}
