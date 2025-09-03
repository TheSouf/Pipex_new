/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:40:59 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/19 22:21:42 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			total_size;
	size_t			i;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	tmp = malloc(total_size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*int main(void)
{
	char *tmp;
	tmp = (char *) ft_calloc(5, sizeof(char));
	ft_strlcpy(tmp, "0123456789", 11);
	printf("result:%s\n", tmp);
	free (tmp);
	return(0);
}*/
