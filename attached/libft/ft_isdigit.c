/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:52:48 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:08:09 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	test1 = '0';
	char	test2 = '1';
	char	test3 = 'a';

	printf("test1 %c : %d\n", test1, ft_isdigit(test1));
	printf("test1 %c : %d\n", test2, ft_isdigit(test2));
	printf("test1 %c : %d\n", test3, ft_isdigit(test3));
	return (0);
}
*/