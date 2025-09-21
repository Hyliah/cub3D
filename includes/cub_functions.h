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

#ifndef CUB_FUNCTIONS_H
# define CUB_FUNCTION_H


/* PARSING */

/* SCREEN */
int		handle_key(int keycode, t_cub *cub);

void	create_window(t_cub *cub);
void 	draw_minimap(t_cub *cub);

/* MALLOC & EXIT */
int		clean_exit(t_cub *cub);

void	free_tab(char ***tab);
void	*free_ptr(void **ptr);
void	free_mid_tab(t_cub *cub, char ***tab, int i);

/* UTILS */
void	init_struct(t_cub *cub);

void	pixel_put(t_graphic *graph, int x, int y, int color);
char    *get_data_addr(t_graphic *g, int *bpp, int *size_line, int *endian);

#endif