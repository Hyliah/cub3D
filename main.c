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
    // créer fonction de mise a 0 des structures
    create_window(&cub);
    mlx_key_hook(cub.graphic.win_ptr, handle_key, &cub);
	mlx_loop(cub.graphic.mlx_ptr);
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

    // char map_data[14][34] = {
    // "111111111111111111111111111111111",
    // "100000000011000000000000100000001",
    // "101100000111000000000000100000001",
    // "100100000000000000000000100000001",
    // "111111111011000001110000000000001",
    // "100000000011000001110111111111111",
    // "111101111111110111000000100010001",
    // "111101111111110111010100100010001",
    // "110000001101010111000000100010001",
    // "100000000000000011000000100010001",
    // "100000000000000011010100100010001",
    // "110000011101010111110111100011101",
    // "111101111110101101111010001000001",
    // "111111111111111111111111111111111"
    // };

    //cub->map.map_tab = map_data;
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