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

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef enum s_dir
{
	NORTH, // = 0
	EAST, // = 1
	SOUTH, // = 2
	WEST // = 3
}   t_dir;

typedef struct s_player
{
	int	    pos_x;
	int	    pos_y;
	t_dir   dir;
}	t_player;

typedef struct s_map
{
	int		height;
	int		width;
	char    **map_tab;
}	t_map;

typedef struct s_setting // struct pour recupérer les infos sur Parsing
{
	int     c_color //ceiling color 
	int     f_color //floor color
	t_dir	start_dir //le truc nord/sud/est/west
}

typedef struct s_graphic // repris de mon so_long
{
	void	*mlx_ptr; //me souviens plus quoi comment 
	void	*win_ptr; // ca non plus mais seems like ce sera utile
	void	*img_w;
	void	*img_e;
	void	*img_s;
	void	*img_n;
	int		s_width;
	int		s_height;
}	t_graphic;

typedef struct s_cub
{
	t_map       map
	t_player    player
	t_setting   setting
	s_graphic   graphic
}

#endif