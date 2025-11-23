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

#ifndef CUB_FUNCTIONS_H
# define CUB_FUNCTIONS_H

# include "cub.h"

/* PARSING */
char	**alloc_map_line(t_cub *cub, char **map, int *count, char *line);
void	dup_map(t_cub *cub, char **new, int i, char *line);
char	**cpy_map(t_cub *cub);

void	check_arg(t_cub *cub, int ac, char **av);
void	check_cub(t_cub *cub, char *pathname);
void	check_file_access(t_cub *cub, char *pathname);

void	check_invalid_char(t_cub *cub);
void	check_line_empty_in_map(t_cub *cub);
int		is_map_bottom_line(char *line);

void	check_texture(t_cub *cub);
void	check_access_texture(t_cub *cub);
void	check_color(t_cub *cub);

void	parse_color_line(t_cub *cub, char *line);
void	parse_color_floor(t_cub *cub, t_rgb color);
void	parse_color_ceiling(t_cub *cub, t_rgb color);
int		rgb_to_hex(t_rgb color);
t_bool	check_comma(char *str);

void	parse_text_no(t_cub *cub, char *path, char **split);
void	parse_text_so(t_cub *cub, char *path, char **split);
void	parse_text_ea(t_cub *cub, char *path, char **split);
void	parse_text_we(t_cub *cub, char *path, char **split);
void	check_duplicate_texture(t_cub *cub);

t_rgb	parse_rgb(t_cub *cub, char *str);
t_rgb	convert_and_check_rgb(t_cub *cub, char **rgb);
void	check_rgb_format(t_cub *cub, char *str);
void	check_no_space_between_digits(t_cub *cub, char *str, int i);
void	check_rgb_component(t_cub *cub, char *comp, char **rgb);

void	parse_texture_line(t_cub *cub, char *line);
void	empty_texture_line(t_cub *cub, char *line);
char	**split_texture_line(t_cub *cub, char *line);
void	parse_orientation(t_cub *cub, char **split);

void	parsing(t_cub *cub, int ac, char **av);
void	parse_file(t_cub *cub, char *pathname);
void	process_config_line(t_cub *cub, char *line);
void	process_map_line(t_cub *cub, char *line);
void	finalize_map_parsing(t_cub *cub);

void	check_player(t_cub *cub);
void	check_too_many_players(t_cub *cub);
void	check_no_player(t_cub *cub);
void	init_player(t_cub *cub, int x, int y, char dir);
void	init_player_angle(t_player *player);

void	ft_error(t_error error);

int		is_config_line(char *line);
int		is_map_line(char *line);
int		is_empty_line(char *line);
int		is_texture_line(char *line);
int		is_color_line(char *line);

char	*get_next_valid_line(t_cub *cub, int fd);
int		get_map_width(char **map, int height);
int		get_map_height(char **map);

void	ft_strtrim_newline(char *line);
void	ft_strtrim_spaces(char *s);
int		open_cub_file(t_cub *cub, char *pathname);
int		ft_strcmp(char *s1, char *s2);
void	check_rgb_component_length(t_cub *cub, char *comp, char **rgb);

void	free_textures(t_cub *cub);
void	free_map(t_cub *cub);
void	check_size(t_cub *cub);

void	check_wall(t_cub *cub);
void	check_size(t_cub *cub);

/* CUSTOM MLX*/
t_hex_c	get_pixel(t_img *img, int x, int y);
void	merge_screens(t_cub *cub);
void	set_pixel(t_img *img, int x, int y, t_hex_c color);

/* SCREEN */
void	move_player(t_cub *cub);
int		create_window(t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);

/* OVERLAY ELEMENTS */
t_img	*move_weapon(t_cub *cub);
int		init_opening_screen(t_cub *cub);
int		init_overlays_weapons(t_cub *cub);
int		opening_screen_handle(t_cub *cub, int keycode);

/* RAYCASTING */
void	raycasting(t_cub *cub);
void	frame_time(t_cub *cub);
void	limit_fps(t_cub *cub);
void	texture_cal(t_cub *cub, int x, int side);
int		dda(t_cub *cub);
int		init_walls(t_cub *cub);
int		cal_range(t_cub *cub, t_bool is_start);

/* MATH */
void	cal_map(t_cub *cub);
void	cal_view(t_cub *cub);
void	cal_step(t_cub *cub);
void	cal_ray_dir(t_cub *cub);
void	cal_side_dist(t_cub *cub);
void	cal_delta_dist(t_cub *cub);
void	cal_line_height(t_cub *cub);
void	cal_camera_x(t_cub *cub, int x);
void	cal_perp_wall_dist(t_cub *cub, int side);

/* MINIMAP*/
void	mm_creation(t_cub *cub);
void	mm_player_draw(t_cub *cub, int color);

/* MALLOC & EXIT */
int		clean_exit(t_cub *cub);
int		clean_exit_parsing(t_cub *cub);
void	free_map(t_cub *cub);
void	*free_ptr(void **ptr);
void	free_tab(char ***tab);
void	free_textures(t_cub *cub);
void	free_t_img(t_cub *cub, t_img *img);
void	free_mid_init(t_cub *cub);
void	free_mid_tab(t_cub *cub, char ***tab, int i);
void	safe_destroy_image(void *mlx_ptr, void **img_ptr);

/* UTILS */
void	init_struct(t_cub *cub);
void	init_t_imgs(t_cub *cub);

/* MOUSE */
int		mouse_press(int button, int x, int y, t_cub *cub);
int		mouse_release(int button, int x, int y, t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);

#endif