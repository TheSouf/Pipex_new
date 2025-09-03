/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:47:18 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/13 15:33:27 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			d;

	d = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char *)&s[i]);
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "La vie est belle";
	int c = 'r';
	printf("Resultat:%s\n", ft_strchr(str, c));
	printf("Resultat de la fonction de base : %s\n", strchr(str, c));
	return(0);
}*/