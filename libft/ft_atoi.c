/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:31:52 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/19 22:26:16 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(unsigned long long result, int sign)
{
	if (result > 9223372036854775807 && sign > 0)
		return (-1);
	if (result > 9223372036854775807 && sign < 0)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	result;
	int					check;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		check = ft_overflow(result, sign);
		if (check != 1)
			return (check);
		i++;
	}
	return ((int)result * sign);
}
/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = NULL;
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}*/
