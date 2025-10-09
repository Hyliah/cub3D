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

# define G_NAME	"Cub Crossing : La folle aventure de Sirius et Pepito en 3D"

// pour les wall textures
#define WTN "./src/images/wall_textures/"
#define WTS "./src/images/wall_textures/"
#define WTE "./src/images/wall_textures/"
#define WTW "./src/images/wall_textures/"

# ifdef __APPLE__
// pour l opening screen
# define OVRLP "./src/images/overlay/overlay_pepito_mac.xpm"
# define OVRLS "./src/images/overlay/overlay_sirius_mac.xpm"
# elif defined(__linux__)
// pour l opening screen
# define OVRLP "./src/images/overlay/overlay_pepito_lin.xpm"
# define OVRLS "./src/images/overlay/overlay_sirius_lin.xpm"
# endif

# ifdef __APPLE__
// pour l opening screen
# define OS "./src/images/opening_screen/os.xpm"
# define OSS "./src/images/opening_screen/os_si.xpm"
# define OSP "./src/images/opening_screen/os_pep.xpm"
# elif defined(__linux__)
// pour l opening screen
# define OS "./src/images/opening_screen/open_screen.xpm"
# define OSS "./src/images/opening_screen/os_sirius.xpm"
# define OSP "./src/images/opening_screen/os_pepito.xpm"
# endif

# ifdef __APPLE__
# define MM_MAX_W 5500
# define MM_MAX_H 310
# elif defined(__linux__)
# define MM_MAX_W 680
# define MM_MAX_H 470
# endif

typedef unsigned char t_rgba;
typedef unsigned int t_hex_c;

// 0xFFFFFF = rbg 255 255 255
// sky is better : 67a0fc
// floor is better in baed8e

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
	// gestion des fps
	double		new_time;
	double		old_time;
	// position of the player on the map
	float		pos_x;
	float		pos_y;
	// direction of the player -> vertical lane in front of the player
	float		dir_x;
	float		dir_y;
	// camera plane -> horizontal lane of the player
	float		pl_x;
	float		pl_y;
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
	void	*img_w;
	void	*img_e;
	void	*img_s;
	void	*img_n;

}	t_graphic;

typedef struct s_oscreen
{
	t_bool	is_sirius;
	t_img	img_olay;
	void	*img_os;
	void	*img_si;
	void	*img_pe;
	void	*img_ols; //image overlay sirius
	void	*img_olp; //image overlay pepito
}	t_oscreen;

typedef struct s_cub
{
	t_oscreen	oscreen;
	t_bool		game_on;
	t_map		map;
	t_key		key;
	t_mmap		mmap;
	t_player	player;
	t_setting	setting;
	t_graphic	graphic;
}	t_cub;

#endif