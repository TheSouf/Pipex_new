/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:09:32 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/06 21:59:05 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include "../libft/libft.h"

/*Fonctions pour free*/
void	free_the_array(char	**array);

/*Fonctions pour trouver le chemin*/
char	*find_the_path(char *cmd, char **env);
char	*build_the_path(char *dir, char *cmd);
char	*get_the_path(char **env);
char	**execute_cmd(char *argv, char **env);

/*Fonctions pour les gestions d'erreurs*/
void	error_and_exit(char *error_msg);
void	child_error_and_exit(char *error_msg, int *fd);

#endif