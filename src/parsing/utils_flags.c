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

// test test test 
int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3)
		|| line[0] == 'F'
		|| line[0] == 'C')
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}


// modif le 16 oct mais pas sure 
// renvoie 1 si la ligne continet un element de map donc 0 1 N S E W
// int	is_map_line(char *line)
// {
// 	int	i;

// 	if (!line)
// 		return (0);
// 	i = 0;
// 	while ( line[i] == ' ' || line[i] == '	')
// 		i++;
// 	if (line[i] == '\0')
// 		return (0);
// 	while (line[i])
// 	{
// 		if (line[i] == '0' || line[i] == '1'
// 			|| line [i] == 'N' || line[i] == 'S'
// 			|| line[i] == 'E' || line[i] == 'W')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }


// Renvoie 1 si empty 
//new version si ligne est aussi avec juste espace ou tab 
int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') // ajout \r ? important ? 
			return (0);
		i++;
	}
	return (1);
}


// renvoie 1 si la ligne est une ligen de texture
int	is_texture_line(char *line)
{
	//printf("rentre dans la fonction is_texture line\n");
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		return (1);
	//printf("is texture line presente\n");
	return (0);
}

//renvoie 1 si la ligne est une couleur pour F et C 
int	is_color_line(char *line)
{
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}