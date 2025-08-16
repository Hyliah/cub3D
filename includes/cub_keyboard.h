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

#ifndef CUB_KEYBOARD_H
# define CUB_KEYBOARD_H

/*
X11_ is interface graphic of linux that is used by the mlx
*/

# define NO_EVENT_MASK 0
# define KEY_PRESS_MASK 1
# define KEY_RELEASE_MASK 2
# define BUTTON_PRESS_MASK 4
# define BUTTON_RELEASE_MASK 8
# define ENTER_WINDOW_MASK 16
# define LEAVE_WINDOW_MASK 32
# define POINTER_MOTION_MASK 64
# define POINTER_MOTION_HINT_MASK 128
# define BUTTON1_MOTION_MASK 256
# define BUTTON2_MOTION_MASK 512
# define BUTTON3_MOTION_MASK 1024
# define BUTTON4_MOTION_MASK 2048
# define BUTTON5_MOTION_MASK 4096
# define BUTTON_MOTION_MASK 8192
# define KEYMAP_STATE_MASK 16384
# define EXPOSURE_MASK 32768
# define VISIBILITY_CHANGE_MASK 65536
# define STRUCTURE_NOTIFY_MASK 131072
# define RESIZE_REDIRECT_MASK 262144
# define SUBSTRUCTURE_NOTIFY_MASK 524288
# define SUBSTRUCTURE_REDIRECT_MASK 1048576
# define FOCUS_CHANGE_MASK 2097152
# define PROPERTY_CHANGE_MASK 4194304
# define COLORMAP_CHANGE_MASK 8388608
# define OWNER_GRAB_BUTTON_MASK 16777216

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 6
# define ENTER_NOTIFY 7
# define LEAVE_NOTIFY 8
# define FOCUS_IN 9
# define FOCUS_OUT 10
# define KEYMAP_NOTIFY 11
# define EXPOSE 12
# define GRAPHICS_EXPOSE 13
# define NO_EXPOSE 14
# define VISIBILITY_NOTIFY 15
# define CREATE_NOTIFY 16
# define DESTROY_NOTIFY 17
# define UNMAP_NOTIFY 18
# define MAP_NOTIFY 19
# define MAP_REQUEST 20
# define REPARENT_NOTIFY 21
# define CONFIGURE_NOTIFY 22
# define CONFIGURE_REQUEST 23
# define GRAVITY_NOTIFY 24
# define RESIZE_REQUEST 25
# define CIRCULATE_NOTIFY 26
# define CIRCULATE_REQUEST 27
# define PROPERTY_NOTIFY 28
# define SELECTION_CLEAR 29
# define SELECTION_REQUEST 30
# define SELECTION_NOTIFY 31
# define COLORMAP_NOTIFY 32
# define CLIENT_MESSAGE 33
# define MAPPING_NOTIFY 34
# define GENERIC_EVENT 35
# define LAST_EVENT 36 
# define SHIFT_MASK 1
# define LOCK_MASK 2
# define CONTROL_MASK 4
# define MOD1_MASK 8
# define MOD2_MASK 16
# define MOD3_MASK 32
# define MOD4_MASK 64
# define MOD5_MASK 128
#endif 
