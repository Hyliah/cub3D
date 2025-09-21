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

void    hardcode_map(t_cub *cub);

int main (int ac, char **av)
{
    t_cub   cub;
    (void)ac;
    (void)av;

    hardcode_map(&cub);
    init_struct(&cub);
    create_window(&cub);
	mlx_loop(cub.graphic.mlx_ptr);
    mlx_key_hook(cub.graphic.win_ptr, handle_key, &cub);
    return (0);
}

void    hardcode_map(t_cub *cub)
{
    cub->player.pos_x = 26;
    cub->player.pos_y = 11;
    cub->player.dir_x = -1;
    cub->player.dir_y = 0;
    cub->player.pl_x = 0;
    cub->player.pl_y = 0.66;
    cub->player.old_time = 0;
    cub->player.new_time = 0;

    cub->setting.start_dir = NORTH;
    // cub->setting.c_color = 225,30,0;
    // cub->setting.f_color = 220,100,0;

    cub->map.height = 14;
    cub->map.width = 34;
}
// AUTHORIZED FUNCTIONS :

// • open, close, read, write, printf, malloc, 
// free, perror, strerror, exit, gettimeofday.

// • All functions of the mat library (-lm man man 3 math).
// • gettimeofday()
// • All functions of the MinilibX library.
// • Libft