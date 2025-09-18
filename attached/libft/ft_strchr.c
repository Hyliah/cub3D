/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:07:37 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:10:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == d)
			return ((char *) s);
		s++;
	}
	if (d == '\0')
		return ((char *) s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char	str[] = "Hello world";

	char *result = ft_strchr(str, 'l');
	printf(" caractere trouve a la position %ld\n", result - str);
	//
	char *resultat = strchr(str, 'l');
	printf(" caractere trouve a la position %ld\n", resultat - str);
	return (0);
}
*/