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
	//unfructuous_malloc(cub);
	(void)cub;
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
