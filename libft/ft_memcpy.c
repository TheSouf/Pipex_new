/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:55 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/15 13:50:48 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*(d++) = *(s++);
		n--;
	}
	return (dst);
}
/*#include <stdio.h>

int	main(void)
{
	char d[10];
	const char s[] = "123456789";
	printf("Resultat avant utilisation de la fonction:%s\n", d);
	ft_memcpy(d, s, 10);
	printf("Après utilisation de la fonction :%s\n", d);
	memcpy(d, s, 10);
	printf("test de la fonction de base :%s\n", d);
	return (0);
}*/