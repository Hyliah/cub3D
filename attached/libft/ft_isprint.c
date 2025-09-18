/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:52:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:08:13 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main()
{
	char test1 = 'a';
	char test2 = '2';
	char test3 = ' ';
	char test4 = 0;

	printf(" test1 %c : %d\n", test1, ft_isprint(test1));
	printf(" test2 %c : %d\n", test2, ft_isprint(test2));
	printf(" test3 %c : %d\n", test3, ft_isprint(test3));
	printf(" test4 %c : %d\n", test4, ft_isprint(test4));
	return (0);
}
*/