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

static void check_up_and_down(t_cub *cub, char **map, int *x, int *y);
static void err_wall(t_cub *cub);

void	check_wall(t_cub *cub)
{
    int		y;
    int		x;
    char	**map;
    
    map = cub->map.map_tab;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '0')
            {
                if (y == 0 || x == 0 || !map[y + 1])
                    err_wall(cub);
				check_up_and_down(cub, map, &x, &y);
                if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
                    || map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
                    err_wall(cub);
            }
            x++;
        }
        y++;
    }
}

static void err_wall(t_cub *cub)
{
	ft_error(ERR_MAP_WALLS);
    clean_exit_parsing(cub);
}

static void check_up_and_down(t_cub *cub, char **map, int *x, int *y)
{
	int		len;
	int		above_len;
    int		below_len;

	len = ft_strlen(map[*y]);
	above_len = 0;
    if (map[*y - 1])
		above_len = ft_strlen(map[*y - 1]);
	below_len = ft_strlen(map[*y + 1]);
	if (*x >= len - 1 || *x >= above_len || *x >= below_len)
	{
		ft_error(ERR_MAP_WALLS);
		clean_exit_parsing(cub);
	}
}
// version non refacto 
// void	check_wall(t_cub *cub)
// {
//     int		y;
//     int		x;
//     char	**map;
//     int		len;
//     int		above_len;
//     int		below_len;

//     map = cub->map.map_tab;
//     y = 0;
//     while (map[y])
//     {
//         len = ft_strlen(map[y]);
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == '0')
//             {
//                 if (y == 0 || x == 0)
//                 {
//                     ft_error(ERR_MAP_WALLS);
//                     clean_exit_parsing(cub);
//                 }
//                 if (!map[y + 1])
//                 {
//                     ft_error(ERR_MAP_WALLS);
//                     clean_exit_parsing(cub);
//                 }
//                 above_len = 0;
//                 if (map[y - 1])
//                     above_len = ft_strlen(map[y - 1]);
//                 below_len = ft_strlen(map[y + 1]);
//                 if (x >= len - 1 || x >= above_len || x >= below_len)
//                 {
//                     ft_error(ERR_MAP_WALLS);
//                     clean_exit_parsing(cub);
//                 }
//                 if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
//                     || map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
//                 {
//                     ft_error(ERR_MAP_WALLS);
//                     clean_exit_parsing(cub);
//                 }
//             }
//             x++;
//         }
//         y++;
//     }
// }