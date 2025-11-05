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
char	**alloc_map_line(t_cub *cub, char **map, int *count, char *line);
void	dup_map(t_cub *cub, char **new, int i, char *line);

int		is_invalid_position(char **map, int y, int x);
void	check_line_walls(t_cub *cub, int y);
void	check_wall(t_cub *cub);

void	check_arg(t_cub *cub, int ac, char **av);
void	check_cub(t_cub *cub, char *pathname);
void	check_file_access(t_cub *cub, char *pathname);

void	flood_fill(t_cub *cub, int y, int x);
int		is_touching_void(t_cub *cub);
void	check_valid_map_flood(t_cub *cub);

void	check_invalid_char(t_cub *cub);
void	check_line_empty_in_map(t_cub *cub);
void	check_wall(t_cub *cub);
int		is_map_bottom_line(char *line);

void	check_texture(t_cub *cub);
void	check_access_texture(t_cub *cub);
void	check_color(t_cub *cub);

void	parse_color_line(t_cub *cub, char *line);
void	parse_color_floor(t_cub *cub, t_rgb color);
void	parse_color_ceiling(t_cub *cub, t_rgb color);
int		rgb_to_hex(t_rgb color);

void	parse_text_no(t_cub *cub, char *path, char **split);
void	parse_text_so(t_cub *cub, char *path, char **split);
void	parse_text_ea(t_cub *cub, char *path, char **split);
void	parse_text_we(t_cub *cub, char *path, char **split);

t_rgb	parse_rgb(t_cub *cub, char *str);
void	check_rgb_format(t_cub *cub, char *str);
void	check_no_space_between_digits(t_cub *cub, char *str, int i);
void	check_rgb_component(t_cub *cub, char *comp);
t_rgb	convert_and_check_rgb(t_cub *cub, char **rgb);

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

void	free_textures(t_cub *cub);
void	free_map(t_cub *cub); // test
int		tab_height(char **src); // test 
char	**dup_tab(char **src);
void	print_debug_settings(t_setting *set); // a supp 

/* SCREEN */
int		handle_key(int keycode, t_cub *cub);

void	create_window(t_cub *cub);
void	draw_minimap(t_cub *cub);

/* MALLOC & EXIT */
int		clean_exit(t_cub *cub);
int		clean_exit_parsing(t_cub *cub);

void	free_tab(char ***tab);
void	*free_ptr(void **ptr);
void	free_mid_tab(t_cub *cub, char ***tab, int i);

/* UTILS */
void	init_struct(t_cub *cub);

void	pixel_put(t_graphic *graph, int x, int y, int color);
char    *get_data_addr(t_graphic *g, int *bpp, int *size_line, int *endian);

#endif