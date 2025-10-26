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

//void        hardcode_map(t_cub *cub, char *arg);
//static void	print_tab(char **tab);

int main (int ac, char **av)
{
    t_cub   cub;
    (void)ac;
    (void)av;

    init_struct(&cub);
	parsing(&cub, ac, av);
    //hardcode_map(&cub, av[2]);
    //print_tab(cub.map.map_tab);
    // create_window(&cub);
	// mlx_loop(cub.graphic.mlx_ptr);
    // mlx_key_hook(cub.graphic.win_ptr, handle_key, &cub);
    free_textures(&cub);
    free_map(&cub);
	return (0);
}


/* laide fonction a suppimer des que le parsing sera fait */
void    hardcode_map(t_cub *cub, char *arg)
{
    cub->player.pos_x = 26;
    cub->player.pos_y = 11;
    cub->player.dir_x = -1;
    cub->player.pl_y = 0.66;

    cub->setting.start_dir = NORTH;
    // cub->setting.c_color = 225,30,0;
    // cub->setting.f_color = 220,100,0;

    cub->map.height = 9;
    cub->map.width = 18;

    int	i;
    char *line;

	i = 0;
	cub->map.map_tab = malloc(sizeof(char *) * (cub->map.height + 1));
	int fd = open(arg, O_RDONLY);

	while (i < cub->map.height)
	{
        printf("%d\n", i);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		cub->map.map_tab[i] = ft_strndup(line, cub->map.width);
		free (line);
		i++;
	}
	cub->map.map_tab[i] = NULL;
	close(cub->setting.fd);
}
// AUTHORIZED FUNCTIONS :

// • open, close, read, write, printf, malloc, 
// free, perror, strerror, exit, gettimeofday.

// • All functions of the mat library (-lm man man 3 math).
// • gettimeofday()
// • All functions of the MinilibX library.
// • Libft


// static void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 1;
// 	while (tab && tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }

void	print_debug_settings(t_setting *set)
{
	printf("\n========== DEBUG SETTINGS ==========\n");

	printf("Textures:\n");
	printf("  NO: %s\n", set->tex_no ? set->tex_no : "(null)");
	printf("  SO: %s\n", set->tex_so ? set->tex_so : "(null)");
	printf("  WE: %s\n", set->tex_we ? set->tex_we : "(null)");
	printf("  EA: %s\n", set->tex_ea ? set->tex_ea : "(null)");

	printf("\nFlags:\n");
	printf("  has_tex_no: %d\n", set->has_tex_no);
	printf("  has_tex_so: %d\n", set->has_tex_so);
	printf("  has_tex_we: %d\n", set->has_tex_we);
	printf("  has_tex_ea: %d\n", set->has_tex_ea);
	printf("  has_floor:  %d\n", set->has_floor);
	printf("  has_ceiling:%d\n", set->has_ceiling);

	printf("\nColors (RGB):\n");
	printf("  Floor:   R=%d, G=%d, B=%d\n", set->rgb_f_color.r, set->rgb_f_color.g, set->rgb_f_color.b);
	printf("  Ceiling: R=%d, G=%d, B=%d\n", set->rgb_c_color.r, set->rgb_c_color.g, set->rgb_c_color.b);

	printf("\nStart direction: ");
	if (set->start_dir == NORTH)
		printf("NORTH\n");
	else if (set->start_dir == SOUTH)
		printf("SOUTH\n");
	else if (set->start_dir == EAST)
		printf("EAST\n");
	else if (set->start_dir == WEST)
		printf("WEST\n");
	else
		printf("(not set)\n");

	printf("====================================\n\n");
}
