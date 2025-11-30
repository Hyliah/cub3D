/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:06:40 by hlichten          #+#    #+#             */
/*   Updated: 2025/11/30 02:06:44 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Prints an error message for failed memory allocation and exits safely.
 *
 * Calls clean_exit() to free all allocated resources.
 * Then terminates the program.
 *
 * @param cub Main game structure.
 */
void	unfructuous_malloc(t_cub *cub)
{
	ft_putstr_fd("Unfructuous Malloc: Cannot allocate memory", STDERR_FILENO);
	clean_exit(cub);
	exit(EXIT_FAILURE);
}

/**
 * @brief Frees partially allocated 2D array up to index i, then exits.
 *
 * This function is used when a malloc fails partway through allocation.
 * It frees all rows up to index i, the array pointer itself, and then
 * calls unfructuous_malloc() to handle program termination.
 *
 * @param cub Main game structure.
 * @param tab Pointer to the 2D array.
 * @param i Number of rows to free.
 */
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

/**
 * @brief Frees a null-terminated 2D array and sets the pointer to NULL.
 *
 * Iterates over each row, frees it, then frees the array itself.
 *
 * @param tab Pointer to the 2D array to free.
 */
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

/**
 * @brief Frees a pointer and sets it to NULL.
 *
 * Useful for safely freeing dynamically allocated memory 
 * and avoiding dangling pointers.
 *
 * @param ptr Address of the pointer to free.
 * @return void* Always returns NULL for convenience in assignments.
 */
void	*free_ptr(void **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

/**
 * @brief Frees the map structure and resets its dimensions.
 *
 * Frees:
 *  - the map 2D array
 *  - the current line buffer
 *
 * Resets width and height to 0.
 *
 * @param cub Pointer to the main game structure.
 */
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
