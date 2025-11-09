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

int game_loop(t_cub *cub);
//void	hardcode_map(t_cub *cub, char *arg);



// void debug_log(const char *msg)
// {
//     FILE *f = fopen("debug.log", "a");
//     if (f)
//     {
//         fprintf(f, "%s\n", msg);
//         fclose(f);
//     }
// }

int main (int ac, char **av)
{

	t_cub   cub;
	(void)ac;
	(void)av;
	if (ac == 2)
	{
		// premiers checks ici

		init_struct(&cub);
		// hardcode de la map -> enlever quand parsing est fait
		//hardcode_map(&cub, av[1]);
		// mettre le parsing ici
		parsing(&cub, ac, av);
		if (create_window(&cub))
			return (1);
		mlx_hook(cub.graphic.win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, &cub);
		mlx_hook(cub.graphic.win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &cub);
		mlx_loop_hook(cub.graphic.mlx_ptr, game_loop, &cub);
		mlx_loop(cub.graphic.mlx_ptr);
	}
	return (0);
}

int game_loop(t_cub *cub)
{
	if (cub->game_on)
		limit_fps(cub);
	move_player(cub);
	return 0;
}

// /* laide fonction a suppimer des que le parsing sera fait */
// void    hardcode_map(t_cub *cub, char *arg)
// {
// 	cub->player.pos_x = 10.5;
// 	cub->player.pos_y = 5.5;
// 	cub->player.dir_x = 0.0f;
// 	cub->player.dir_y = -1.0f;
// 	cub->player.pl_x = 0.66f;
// 	cub->player.pl_y = 0.0f;
// 	// je crois pas que ce truc soit utile en fait / doublon avec le player
// 	cub->setting.start_dir = NORTH;
	
// 	cub->player.angle = 90;

// 	cub->map.height = 9;
// 	cub->map.width = 17;

// 	/* mettre en place une double taille en fonction de la taille ? */
// 	cub->mmap.mm_hei = cub->map.height * 32;
// 	cub->mmap.mm_wid = cub->map.width * 32;

// 	cub->setting.c_color = 0xa1c8f4;
// 	cub->setting.f_color = 0x8fa959;

// 	int	i;
// 	char *line;

// 	i = 0;
// 	cub->map.map_tab = malloc(sizeof(char *) * (cub->map.height + 1));
// 	if (!cub->map.map_tab)
// 		return (perror("Error: malloc failed"));
// 	cub->setting.fd = open(arg, O_RDONLY);
// 	if (cub->setting.fd == -1)
// 		return (ft_putstr_fd("Error : incorrect fd\n", 2));
// 	while (i < cub->map.height)
// 	{
// 		line = get_next_line(cub->setting.fd);
// 		if (line == NULL)
// 			break ;
// 		cub->map.map_tab[i] = ft_strndup(line, cub->map.width);
// 		if (cub->map.map_tab[i] == NULL)
// 			free_mid_tab(cub, &cub->map.map_tab, i);
// 		free (line);
// 		i++;
// 	}
// 	cub->map.map_tab[i] = NULL;
// 	close(cub->setting.fd);
// }

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
