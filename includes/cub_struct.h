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


typedef struct s_rgb
{
    unsigned char	r;
    unsigned char 	g;
    unsigned char 	b;
}   t_rgb;

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
	t_dir   	dir;
	int			has_player; // flag 
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
	int		fd;
	t_rgb   c_color; //ceiling color // modif avec struct rgb
	t_rgb   f_color; //floor color // modif avec struct rgb
	t_dir	start_dir; //le truc nord/sud/est/west

	char    *tex_no;// stockage des textures 
    char    *tex_so;
    char    *tex_we;
    char    *tex_ea;

	int     has_floor; // ajout des flags de verif 
    int     has_ceiling;
    int     has_tex_no;
    int     has_tex_so;
    int     has_tex_we;
    int     has_tex_ea;

}	t_setting;

typedef struct s_graphic // repris de mon so_long
{
	void	*mlx_ptr; //pour creation de la window
	void	*win_ptr; //pour la creation de la window

	// pour la recreation du get data adress sur linux et mac
    void    *img; //buffer image
    char    *addr; //adresse mémoire du buffer
    int     bpp; //bits per pixel
    int     size_line; //longueur d'une ligne
    int     endian; //endianness

	#ifdef __APPLE__
    unsigned int *buffer; //gestion de pixel put sur mac
	#endif
	// en pixel 
	int		s_width;
	int		s_height;
	int		mm_max_width;
	int		mm_max_height;

	//images des murs et leurs liens
	void	*img_w;
	void	*img_e;
	void	*img_s;
	void	*img_n;


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
	ERR_FILE_NOT_FOUND,
	ERR_NO_PLAYER,
	ERR_TOO_MANY_PLAYERS,
	ERR_MAP_LINE,
	ERR_COLOR,
}	t_error;

#endif