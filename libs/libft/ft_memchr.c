/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:12:51 by maustel           #+#    #+#             */
/*   Updated: 2024/05/08 15:47:42 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// The memchr() function locates the first occurrence of c (converted to an
// unsigned char) in string s.
// The main differences between strchr and memchr are:
// - strchr stops at a null character, while memchr does not.
// - strchr is used for searching in null-terminated strings, while memchr
//   is used for searching in blocks of memory.
// - strchr does not need a length parameter, while memchr does.

// int main()
// {
// 	char s[] = "12345678";
// 	int c = '5';
// 	int n = 3;
// 	printf("%s", ft_memchr(s, c, n));

// 	return (0);
// }
