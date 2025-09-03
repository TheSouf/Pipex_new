/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:48:20 by sofkhali          #+#    #+#             */
/*   Updated: 2025/04/12 14:51:25 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptrsouf;
	size_t			i;

	i = 0;
	ptrsouf = (unsigned char *)s;
	while (i < n)
	{
		ptrsouf[i] = 0;
		i++;
	}
}
/*#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

int	main(void)
{
	// ===== TEST 1 : Avec un entier (int) =====
	int number = 42;
	printf("AVANT bzero (int): %d\n", number);

	ft_bzero(&number, sizeof(int)); // On zero tout l'int
	printf("APRÈS bzero (int): %d\n\n", number); // Doit afficher 0

	// ===== TEST 2 : Avec un tableau de 3 entiers =====
	int numbers[3] = {10, 20, 30};
	printf("AVANT bzero (int[3]): %d | %d | %d\n", numbers[0], numbers[1],
		numbers[2]);

	ft_bzero(numbers, sizeof(int) * 2); // On zero les 2 premiers entiers
	printf("APRÈS bzero (2 premiers int): %d | %d | %d\n\n", numbers[0],
		numbers[1], numbers[2]);

	// ===== TEST 3 : Avec un float =====
	float pi = 3.14159f;
	printf("AVANT bzero (float): %f\n", pi);

	ft_bzero(&pi, sizeof(float)); // On zero tout le float
	printf("APRÈS bzero (float): %f\n\n", pi); // Doit afficher 0.000000

	// ===== TEST 4 : Comparaison avec la vraie bzero (int) =====
	int x = 123;
	int y = 123;

	ft_bzero(&x, sizeof(int));
	bzero(&y, sizeof(int));

	printf("Comparaison avec bzero officielle (int):\n");
	printf("ft_bzero → %d\n", x);
	printf("bzero    → %d\n", y);

	return (0);
}*/