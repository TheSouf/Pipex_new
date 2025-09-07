/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:02 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/06 22:01:15 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_and_exit(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	child_error_and_exit(char *error_msg, int *fd)
{
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	perror(error_msg);
	exit(EXIT_FAILURE);
}
