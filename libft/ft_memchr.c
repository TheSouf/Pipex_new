/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:48:00 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/19 22:26:29 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	j;
	size_t			i;

	str = (unsigned char *)s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == j)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int	main(void)
{
	char str[] = "Avec du monde";
	int c = 'n';
	char *q = (char *)ft_memchr(str, c, 3);
	printf("Resultat: %s\n", q);
	return(0);
}*/
