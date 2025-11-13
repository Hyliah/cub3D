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

void	unfructuous_malloc(t_cub *cub)
{
	ft_putstr_fd("Unfructuous Malloc: Cannot allocate memory", STDERR_FILENO);
	clean_exit(cub);
	exit(EXIT_FAILURE);
}

void	free_mid_tab(t_cub *cub, char ***tab, int i)
{
	if (!tab && !*tab)
		return ;
	while (i > 0)
	{
		i--;
		free_ptr((void **)&((*tab)[i]));
	}
	free(*tab);
	*tab = NULL;
	unfructuous_malloc(cub);
}

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while ((*tab)[i])
	{
		free_ptr((void **)&((*tab)[i]));
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	*free_ptr(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void	free_map(t_cub *cub)
{
	if (cub->map.map_tab)
		free_tab(&cub->map.map_tab);
	cub->map.height = 0;
	cub->map.width = 0;
	if (cub->map.current_line)
	{
		free(cub->map.current_line);
		cub->map.current_line = NULL;
	}
}
