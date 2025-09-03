/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:46:57 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/19 16:19:28 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*result;
	char			d;

	result = NULL;
	d = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			result = (char *)&s[i];
		i++;
	}
	if (s[i] == d)
		result = (char *)&s[i];
	return (result);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Je veux du vin";
	int c = 'v';
	printf("resultat : %s\n", ft_strrchr(str, c));
	printf("resultat de la f de base : %s\n", strrchr(str, c));
	return(0);
}*/