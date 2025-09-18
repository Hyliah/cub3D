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

/* MALLOC & EXIT */
int		clean_exit(t_cub *cub);

#endif