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

void        hardcode_map(t_cub *cub, char *arg);
//static void	print_tab(char **tab);

int main (int ac, char **av)
{
	t_cub   cub;
	(void)ac;
	(void)av;
	if (ac == 2)
	{
		// premiers checks ici

		// init de la struct
		init_struct(&cub);
		// hardcode de la map -> enlever quand parsing est fait
		hardcode_map(&cub, av[1]);
		// mettre le parsing ici

		// mise en place de la window
		create_window(&cub);
		// gestion des boutons
		mlx_key_hook(cub.graphic.win_ptr, handle_key, &cub);
		// loop la window pour pas quelle se barre
		mlx_loop(cub.graphic.mlx_ptr);
	}
	return (0);
}









/* laide fonction a suppimer des que le parsing sera fait */
void    hardcode_map(t_cub *cub, char *arg)
{
    cub->player.pos_x = 15.5;
    cub->player.pos_y = 4.5;
    cub->player.dir_x = -1;
    cub->player.pl_y = 0.66;

    cub->setting.start_dir = NORTH;
    // cub->setting.c_color = 225,30,0;
    // cub->setting.f_color = 220,100,0;

    cub->map.height = 9;
    cub->map.width = 17;

	/* mettre en place une double taille en fonction de la taille ? */
	cub->mmap.mm_hei = cub->map.height * 32;
	cub->mmap.mm_wid = cub->map.width * 32;

    int	i;
    char *line;

	i = 0;
	cub->map.map_tab = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!cub->map.map_tab)
		return (perror("Error: malloc failed"));
	cub->setting.fd = open(arg, O_RDONLY);
	if (cub->setting.fd == -1)
		return (ft_putstr_fd("Error : incorrect fd\n", 2));
	while (i < cub->map.height)
	{
		line = get_next_line(cub->setting.fd);
		if (line == NULL)
			break ;
		cub->map.map_tab[i] = ft_strndup(line, cub->map.width);
		if (cub->map.map_tab[i] == NULL)
			free_mid_tab(cub, &cub->map.map_tab, i);
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
