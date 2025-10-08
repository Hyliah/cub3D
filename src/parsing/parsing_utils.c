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

// renvoie 1 si la ligne continet un element de map donc 0 1 N S E W
int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| line [i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

// faire empty line . return 1 si empty 
int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while ( line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return(1);
}

// renvoie 1 si la ligne est une ligen de texture
int	is_texture_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (1);
	return (0);
}

//renvoie 1 si la ligne est une couleur pour F et C 
int	is_color_line(char *line)
{
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}