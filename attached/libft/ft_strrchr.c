/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:42:12 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:11:10 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = 0;

	c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return ((char *) last);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	const char s[] = "hello world";
	char *result = ft_strrchr(s, 'l');
	printf("caractere trouve a la position %ld\n", result - s);
	//
	char *resultat = strrchr(s, 'l');
	printf("caractere trouve a la position %ld\n", resultat - s);
	return (0);
}
*/