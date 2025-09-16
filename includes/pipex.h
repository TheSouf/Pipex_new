/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:09:32 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/16 13:12:38 by sofkhali         ###   ########.fr       */
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
int		get_exit_status(int status);

void	run_pipex(char **argv, char **env, int *status2);

#endif
