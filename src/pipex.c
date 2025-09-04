/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:09 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/04 21:54:50 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    first_child_processus(char *av[], char *env[], int *fd)
{
	int		infile;
	
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error_exit("Error : infile cannot be open.");
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execve(av[2], env);
}

void	second_child_processus(char *av[], char *env[], int *fd)
{
	
}
int	main(void)
{
}
