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

// contain information about the position of the player and FOV
typedef struct s_player
{
	// gestion des fps
	double		new_time;
	double		old_time;
	// position of the player on the map
	double	    pos_x;
	double	    pos_y;
	// direction of the player -> vertical lane in front of the player
	double		dir_x;
	double		dir_y;
	// camera plane -> horizontal lane of the player
	double		pl_x;
	double		pl_y;
	//pas sure si utile
	t_dir   dir;
}	t_player;

// Field of vision is 2 * atan(0.66/1.0)=66°
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

#endif