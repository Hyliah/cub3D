/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:27:05 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:10:08 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset( void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len--)
		*str++ = (char)c;
	return (b);
}
/*
#include <stdio.h>
int main()
{
	char	string[] = "hello world!";
	
	printf("avant fonction : %s\n", string);
	ft_memset(string, '0', 5);
	printf("apres fonction : %s\n", string);
	return (0);
}
*/