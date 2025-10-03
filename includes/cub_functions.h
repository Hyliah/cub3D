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

/* CUSTOM MLX*/
t_hex_c	get_pixel(t_img *img, int x, int y);

void	set_pixel(t_img *img, int x, int y, t_hex_c color);

/* SCREEN */
int		handle_key(int keycode, t_cub *cub);

void	create_window(t_cub *cub);

/* MINIMAP*/
void	mm_player(t_cub *cub);
void	mm_creation(t_cub *cub);

/* MALLOC & EXIT */
int		clean_exit(t_cub *cub);

void	free_tab(char ***tab);
void	*free_ptr(void **ptr);
void	free_mid_tab(t_cub *cub, char ***tab, int i);

/* UTILS */
void	init_struct(t_cub *cub);

#endif