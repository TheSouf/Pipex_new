/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:58 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/19 16:10:18 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrsouf1;
	const unsigned char	*ptrsouf2;
	size_t				i;

	ptrsouf1 = (const unsigned char *)s1;
	ptrsouf2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && ptrsouf1[i] == ptrsouf2[i])
		i++;
	if (i == n)
		return (0);
	return (ptrsouf1[i] - ptrsouf2[i]);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = {1, -5, 3, 4};
	char s2[] = {1, 2, 3, 6};
	ft_memcmp(s1, s2, 2);
	printf("resultat de la différence de bytes : %d\n", ft_memcmp(s1, s2, 2));
	memcmp(s1, s2, 2);
	printf("test de la fonction de base : %d\n", memcmp(s1, s2, 2));
	return(0);
}*/