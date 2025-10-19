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

# include "cub.h"

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef enum s_dir
{
	NORTH, // = 0
	EAST, // = 1
	SOUTH, // = 2
	WEST // = 3
}  	t_dir;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

// contain information about the position of the player and FOV
typedef struct s_player
{
	// position of the player on the map
	float	pos_x;
	float	pos_y;
	// direction of the player -> vertical lane in front of the player
	float	dir_x;
	float	dir_y;
	// camera plane -> horizontal lane of the player -| from dir
	float	pl_x;
	float	pl_y;
	// de -1 a 1 . 0 au centre
	float	cam_x;
	float	cam_y;

	float	ray_dir_x;
	float	ray_dir_y;
	// distance ray has to travel from point to first xy side
	float	side_dist_x;
	float	side_dist_y;
	// distance ray has to travel from 1 side xy to the next
	float	delta_dist_x;
	float	delta_dist_y;
	// distance jusqu au mur
	float	perp_wall_dist;
	// hauteur du mur
	int		line_height;

	int		step_x;
	int		step_y;
	//sur quel carre on est
	int		map_x;
	int		map_y;

	int		angle;

	//pas sure si utile
	t_dir   dir;

}	t_player;

// Field of vision is 2 * atan(0.66/1.0)= 66°
typedef struct s_map
{
	int		height;
	int		width;
	char	**map_tab;
}	t_map;

typedef struct s_setting // struct pour recupérer les infos sur Parsing
{
	int		fd;
	int		c_color; //ceiling color 
	int		f_color; //floor color
	t_dir	start_dir; //le truc nord/sud/est/west
}	t_setting;

typedef struct s_img
{
	void	*img_ptr; //buffer image
	char	*addr_ptr; //adresse mémoire du buffer d image (recup avec get data addr) le tableau 1D
	int		bpp; //bits per pixel -> 1 pixel = 1 int -> 32 bits
	int		size_line; //longueur d'une ligne actuelle de la window
	int		endian; //endianness
	int		width;
	int		height;
}	t_img;

typedef struct s_mmap
{
	t_img	img_mmap;
	t_img	img_player;
	
	int		mm_hei;
	int		mm_wid;
	int		mm_sqr;

	t_bool	mm_show;

}	t_mmap;

// holding key
typedef struct s_key
{
	t_bool	k_a;
	t_bool	k_s;
	t_bool	k_d;
	t_bool	k_w;
	t_bool	k_le;
	t_bool	k_ri;
	t_bool	k_up;
	t_bool	k_do;
	t_bool	k_sh;
}	t_key;

typedef struct s_graphic // repris de mon so_long
{
	void	*mlx_ptr; //pour creation de la window
	void	*win_ptr; //pour la creation de la window

	// en pixel 
	int		s_width;
	int		s_height;
	
	//struct info par screen
	t_img	img_screen;
	
	//images des murs et leurs liens
	t_img	img_e;
	t_img	img_s;
	t_img	img_n;
	t_img	img_w;
	
}	t_graphic;

typedef struct s_oscreen
{
	t_bool	is_sirius;
	t_img	img_olay;
	void	*img_os;
	void	*img_si;
	void	*img_pe;
}	t_oscreen;

typedef struct s_weapons
{
	int		s_nb;
	t_bool	up;
	t_img	img_w1;
	t_img	img_w2;
	t_img	img_w3;
	t_img	img_w4;
	t_img	img_w5;

}	t_weapons;

typedef struct s_fps
{
    double  frame_time;
    double  start_time;
    double  old_time;
}   t_fps;

typedef struct s_cub
{
    t_weapons   weapons;
    t_oscreen   oscreen;
    t_bool      game_on;
    t_map       map;
    t_key       key;
    t_fps       fps;
    t_mmap      mmap;
    t_player    player;
    t_setting   setting;
    t_graphic   graphic;
}   t_cub;


#endif