/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:07 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/03 17:02:53 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    *get_the_path(char **env)
{
    int i;
    
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH", 5) == 0)
            return (env[i] + 5);
        i++;
    }
    return (NULL);
}

char    find_the_path(char *cmd, char **env)
{
    char    **paths;
    char    *path_init;
    char    *temp;
    int i;
    
    path_init = get_the_path(env);
    if (!path_init)
        return (NULL);
    paths = ft_split(path_init, ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        if (!temp)
        ;
    }
}