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

#ifndef CUB_DEFINE_H
# define CUB_DEFINE_H

# define G_NAME	"Cub Crossing : La folle aventure de Sirius et Pepito en 3D"

// pour les wall textures
#define WTN "./src/images/wall_textures/"
#define WTS "./src/images/wall_textures/"
#define WTE "./src/images/wall_textures/"
#define WTW "./src/images/wall_textures/"

# ifdef __APPLE__
// pour le layover
# define OVRLP "./src/images/overlay/overlay_pepito_mac.xpm"
# define OVRLS "./src/images/overlay/overlay_sirius_mac.xpm"
# elif defined(__linux__)
// pour le layover
# define OVRLP "./src/images/overlay/overlay_pepito_lin.xpm"
# define OVRLS "./src/images/overlay/overlay_sirius_lin.xpm"
# endif

# ifdef __APPLE__
// pour les armes
# define W1 "./src/images/weapons/W1_mac.xpm"
# define W2 "./src/images/weapons/W2_mac.xpm"
# define W3 "./src/images/weapons/W3_mac.xpm"
# define W4 "./src/images/weapons/W4_mac.xpm"
# define W5 "./src/images/weapons/W5_mac.xpm"
# elif defined(__linux__)
// pour les armes
# define W1 "./src/images/weapons/w1.xpm"
# define W2 "./src/images/weapons/w2.xpm"
# define W3 "./src/images/weapons/w3.xpm"
# define W4 "./src/images/weapons/w4.xpm"
# define W5 "./src/images/weapons/w5.xpm"
# endif

# ifdef __APPLE__
// pour l opening screen
# define OS "./src/images/opening_screen/os.xpm"
# define OSS "./src/images/opening_screen/os_si.xpm"
# define OSP "./src/images/opening_screen/os_pep.xpm"
# elif defined(__linux__)
// pour l opening screen
# define OS "./src/images/opening_screen/open_screen.xpm"
# define OSS "./src/images/opening_screen/os_sirius.xpm"
# define OSP "./src/images/opening_screen/os_pepito.xpm"
# endif

# ifdef __APPLE__
# define MM_MAX_W 550
# define MM_MAX_H 310
# elif defined(__linux__)
# define MM_MAX_W 680
# define MM_MAX_H 470
# endif

typedef unsigned char t_rgba;
typedef unsigned int t_hex_c;

// 0xFFFFFF = rbg 255 255 255
// sky is better : 67a0fc
// floor is better in baed8e

#endif