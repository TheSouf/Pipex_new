/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:38:49 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/18 16:01:40 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_start;

	src_start = src;
	if (size == 0)
		return (ft_strlen(src));
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	while (*src)
		src++;
	return (src - src_start);
}
/*#include <stdio.h>

int	main(void)
{
	char dst[] = "";
	char src[] = "je veux du pain";
	size_t dstsize = 50;
	printf("resultat: %zu\n", ft_strlcpy(dst, src, dstsize));
	return(0);
}*/