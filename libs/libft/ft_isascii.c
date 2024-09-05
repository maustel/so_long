/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:51:02 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 12:16:08 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
// 	printf("isascii\n");
//     int c = 'a';
//     if (ft_isascii(c) == isascii(c))
//         printf("Ok!\n");
//     c = 128;
//     if (ft_isascii(c) == isascii(c))
//         printf("Ok!\n");
// }