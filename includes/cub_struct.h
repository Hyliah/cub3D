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

typedef enum s_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_dir;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_error
{
	ERR_ARGS,
	ERR_FILE_EXT,
	ERR_MAP_INVALID_CHAR,
	ERR_MAP_INVALID,
	ERR_MEMORY,
	ERR_MAP_WALLS,
	ERR_MAP_PATH,
	ERR_FILE_NOT_FOUND,
	ERR_PLAYER,
	ERR_MAP_LINE,
	ERR_COLOR,
	ERR_TEXTURE,
}	t_error;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	pl_x;
	float	pl_y;
	float	cam_x;
	float	cam_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	int		line_height;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	t_dir	dir;
	double	angle;
	int		has_player;
	t_bool	is_door;
}	t_player;

typedef struct s_map
{
	int		map_start;
	int		map_end;
	int		count_only_one;
	int		height;
	int		width;
	char	**map_tab;
	char	*current_line;
	t_bool	is_door_open;
}	t_map;

typedef struct s_setting
{
	int		fd;
	t_rgb	rgb_c_color;
	t_rgb	rgb_f_color;
	int		c_color;
	int		f_color;
	t_dir	start_dir;

	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;

	int		has_floor;
	int		has_ceiling;
	int		has_tex_no;
	int		has_tex_so;
	int		has_tex_we;
	int		has_tex_ea;
}	t_setting;

typedef struct s_mouse
{
	t_bool	pressed;
	int		last_x;
}	t_mouse;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mmap
{
	t_img	img_mmap;
	t_img	img_player;
	t_bool	mm_show;
	int		mm_hei;
	int		mm_wid;
	int		mm_sqr;

}	t_mmap;

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

typedef struct s_graphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		s_width;
	int		s_height;
	t_img	img_screen;
	t_img	img_e;
	t_img	img_s;
	t_img	img_n;
	t_img	img_w;
	t_img	img_door;
}	t_graphic;

typedef struct s_tex
{
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	float	wall_x;
	float	step;
	float	tex_pos;
}	t_tex;

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
	double	frame_time;
	double	start_time;
	double	old_time;
}	t_fps;

typedef struct s_cub
{
	t_weapons	weapons;
	t_oscreen	oscreen;
	t_bool		game_on;
	t_map		map;
	t_key		key;
	t_tex		tex;
	t_fps		fps;
	t_mouse		mouse;
	t_mmap		mmap;
	t_player	player;
	t_setting	setting;
	t_graphic	graphic;
}	t_cub;

#endif