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

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include "cub.h"

# define G_NAME	"Cub Crossing : New maze adventure"
# define IMG_TEST "./src/images/test.xpm"


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
	int     c_color; //ceiling color 
	int     f_color; //floor color
	t_dir	start_dir; //le truc nord/sud/est/west
}	t_setting;

typedef struct s_graphic // repris de mon so_long
{
	void	*mlx_ptr; //pour creation de la window
	void	*win_ptr; //pour la creation de la window
	void	*img_w;
	void	*img_e;
	void	*img_s;
	void	*img_n;
	int		s_width;
	int		s_height;
}	t_graphic;

typedef struct s_cub
{
	t_map       map;
	t_player    player;
	t_setting   setting;
	t_graphic   graphic;
}	t_cub;

// repris de mon so_long, a update si besoin 
typedef enum e_error
{
	ERR_ARGS,
	ERR_FILE_EXT,
	ERR_MAP_INVALID_CHAR,
	ERR_MAP_INVALID,
	ERR_MAP_SIZE,
	ERR_MAP_WALLS,
	ERR_MAP_PATH,
	ERR_MAP_NOT_FOUND,
}	t_error;

#endif