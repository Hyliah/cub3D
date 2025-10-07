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
void 	check_arg(t_cub *cub, int ac, char **av);
void	check_cub(t_cub *cub, char *pathname);
void	check_file_access(t_cub *cub, char *pathname);

void	check_map(t_cub *cub);
void	check_invalid_char(t_cub *cub);
void	check_line_empty(t_cub *cub);
void	check_wall(t_cub *cub);
void 	check_player(t_cub *cub);

void 	check_texture(t_cub *cub);
void 	check_color(t_cub *cub);

int		is_map_line(char *line);
int		is_texture_line(char *line);
int		is_color_line(char *line);

void	parsing(t_cub *cub, int ac, char **av);
void	parse_file(t_cub *cub, char *pathname);

void	parse_texture_line(t_cub *cub, char *line);
void	parse_color_line(t_cub *cub, char *line);
char	**alloc_map_line(char **map, int *count, char *line);

void	ft_error(t_error error);

/* SCREEN */
int		handle_key(int keycode, t_cub *cub);

void	create_window(t_cub *cub);
void 	draw_minimap(t_cub *cub);

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