/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:40:47 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 12:15:58 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
// 	printf("isalnum\n");
//     int c = 'a';
//     if (ft_isalnum(c) == isalnum(c))
//         printf("Ok!\n");
//     c = '4';
//     if (ft_isalnum(c) == isalnum(c))
//         printf("Ok!\n");
// }