/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:09 by sofkhali          #+#    #+#             */
/*   Updated: 2025/09/09 19:27:20 by sofkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child_processus(char **argv, char **env, int *fd)
{
	int		infile;
	char	**cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		child_error_and_exit(argv[1], fd);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmd = execute_cmd(argv[2], env);
	execve(cmd[0], cmd, env);
	perror("execve failed");
	exit(127);
}

void	second_child_processus(char **argv, char **env, int *fd)
{
	int		outfile;
	char	**cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		child_error_and_exit(argv[4], fd);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	cmd = execute_cmd(argv[3], env);
	execve(cmd[0], cmd, env);
	perror("execve failed");
	exit(127);
}

static int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else
		return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status2;

	if (argc != 5)
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile", STDERR_FILENO);
	if (pipe(fd) == -1)
		error_and_exit("Error");
	pid1 = fork();
	if (pid1 == -1)
		error_and_exit("Error");
	if (pid1 == 0)
		first_child_processus(argv, env, fd);
	pid2 = fork();
	if (pid2 == -1)
		error_and_exit("Error");
	if (pid2 == 0)
		second_child_processus(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status2, 0);
	return (get_exit_status(status2));
}
