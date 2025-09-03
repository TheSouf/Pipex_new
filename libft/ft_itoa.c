/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:48:04 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/15 13:53:06 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
/*#include <stdio.h>

int	main(void)
{
	int numbers[] = {0, 1, -1, 42, -42, 123456789, -123456789, INT_MAX,
		INT_MIN};
	int count = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < count; i++)
	{
		char *str = ft_itoa(numbers[i]);
		if (str)
		{
			printf("ft_itoa(%d) = \"%s\"\n", numbers[i], str);
			free(str);
		}
		else
		{
			printf("ft_itoa(%d) = NULL (Erreur d'allocation)\n", numbers[i]);
		}
	}

	return (0);
}*/