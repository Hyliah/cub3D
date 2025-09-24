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

# define MMW "./src/images/minimap/tile_w.xpm"
# define MMP "./src/images/minimap/tile_p.xpm"
# define MMF "./src/images/minimap/tile_f.xpm"

# define BMW "./src/images/minimap/maxi_mm_w.xpm"
# define BMP "./src/images/minimap/maxi_mm_p.xpm"
# define BMF "./src/images/minimap/maxi_mm_f.xpm"

typedef enum s_dir
{
	NORTH, // = 0
	EAST, // = 1
	SOUTH, // = 2
	WEST // = 3
}   t_dir;

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
	int		fd;
	int     c_color; //ceiling color 
	int     f_color; //floor color
	t_dir	start_dir; //le truc nord/sud/est/west
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
	
	t_bool	maxi_mm;

	//images des murs et leurs liens
	void	*img_w;
	void	*img_e;
	void	*img_s;
	void	*img_n;

	void	*mm_p;
	void	*mm_f;
	void	*mm_w;

}	t_graphic;

typedef struct s_cub
{
	t_map       map;
	t_player    player;
	t_setting   setting;
	t_graphic   graphic;
}	t_cub;

#endif