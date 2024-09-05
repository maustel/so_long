/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:16:41 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 12:16:03 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
// 	printf("isalpha\n");
//     int c = 'a';
//     if (ft_isalpha(c) == isalpha(c))
//         printf("Ok!\n");
//     c = '9';
//     if (ft_isalpha(c) == isalpha(c))
//         printf("Ok!\n");
// }