/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:25:10 by mlaffita          #+#    #+#             */
/*   Updated: 2025/09/18 17:12:59 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	test1 = 'a';
	char	test2 = 'B';
	char	test3 = '0';

	printf("Test avec %c, : %d\n",test1, ft_isalpha(test1));
	printf("Test avec %c, : %d\n",test2, ft_isalpha(test2));
	printf("Test avec %c, : %d\n",test3, ft_isalpha(test3));
	return (0);
}
*/