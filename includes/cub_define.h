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

#ifndef CUB_DEFINE_H
# define CUB_DEFINE_H

# include "cub.h"
# define G_NAME	"Cub Crossing : La folle aventure de Sirius et Pepito en 3D"

# ifdef __APPLE__
// pour le layover
#  define OVRLP "./src/images/overlay/overlay_pepito_mac.xpm"
#  define OVRLS "./src/images/overlay/overlay_sirius_mac.xpm"
# elif defined(__linux__)
// pour le layover
#  define OVRLP "./src/images/overlay/overlay_pepito_lin.xpm"
#  define OVRLS "./src/images/overlay/overlay_sirius_lin.xpm"
# endif

# define DOOR "./src/images/wall_textures/door.xpm"
# define COMMA "Bitch better handle that comma correctly mhm\n"

# ifdef __APPLE__
// pour les armes
#  define W1P "./src/images/weapons/w1pm.xpm"
#  define W2P "./src/images/weapons/w2pm.xpm"
#  define W3P "./src/images/weapons/w3pm.xpm"
#  define W4P "./src/images/weapons/w4pm.xpm"
#  define W5P "./src/images/weapons/w5pm.xpm"
#  define W1S "./src/images/weapons/w1sm.xpm"
#  define W2S "./src/images/weapons/w2sm.xpm"
#  define W3S "./src/images/weapons/w3sm.xpm"
#  define W4S "./src/images/weapons/w4sm.xpm"
#  define W5S "./src/images/weapons/w5sm.xpm"
# elif defined(__linux__)
// pour les armes
#  define W2P "./src/images/weapons/w2p.xpm"
#  define W1P "./src/images/weapons/w1p.xpm"
#  define W3P "./src/images/weapons/w3p.xpm"
#  define W4P "./src/images/weapons/w4p.xpm"
#  define W5P "./src/images/weapons/w5p.xpm"
#  define W1S "./src/images/weapons/w1s.xpm"
#  define W2S "./src/images/weapons/w2s.xpm"
#  define W3S "./src/images/weapons/w3s.xpm"
#  define W4S "./src/images/weapons/w4s.xpm"
#  define W5S "./src/images/weapons/w5s.xpm"
# endif

# ifdef __APPLE__
// pour l opening screen
#  define OS "./src/images/opening_screen/os.xpm"
#  define OSS "./src/images/opening_screen/os_si.xpm"
#  define OSP "./src/images/opening_screen/os_pep.xpm"
# elif defined(__linux__)
// pour l opening screen
#  define OS "./src/images/opening_screen/open_screen.xpm"
#  define OSS "./src/images/opening_screen/os_sirius.xpm"
#  define OSP "./src/images/opening_screen/os_pepito.xpm"
# endif

# ifdef __APPLE__
#  define MM_MAX_W 550
#  define MM_MAX_H 310
# elif defined(__linux__)
#  define MM_MAX_W 680
#  define MM_MAX_H 470
# endif

typedef unsigned char	t_rgba;
typedef unsigned int	t_hex_c;

#endif