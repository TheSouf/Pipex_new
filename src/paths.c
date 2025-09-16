/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:07 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/16 13:09:34 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_the_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*build_the_path(char *dir, char *cmd)
{
	char	*half_path;
	char	*full_path;

	half_path = ft_strjoin(dir, "/");
	if (!half_path)
		return (NULL);
	full_path = ft_strjoin(half_path, cmd);
	free(half_path);
	return (full_path);
}

char	*find_the_path(char *cmd, char **env)
{
	char	**paths;
	char	*path_init;
	char	*complete_path;
	int		i;

	path_init = get_the_path(env);
	if (!path_init)
		return (NULL);
	paths = ft_split(path_init, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		complete_path = build_the_path(paths[i], cmd);
		if (!complete_path)
			return (free_the_array(paths), NULL);
		if (access(complete_path, F_OK | X_OK) == 0)
			return (free_the_array(paths), complete_path);
		free(complete_path);
		i++;
	}
	return (free_the_array(paths), NULL);
}

char	**execute_cmd(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_and_exit("Error: split failed");
	path = find_the_path(cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd("\nError: command not found\n", STDERR_FILENO);
		free_the_array(cmd);
		exit(127);
	}
	free(cmd[0]);
	cmd[0] = path;
	return (cmd);
}
