/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:27:43 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/20 11:39:52 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (EXIT_FAILURE);
	ft_pipex(env, av);
	return (0);
}

void	ft_pipex(char **env, char **av)
{
	int		fd[2];
	pid_t	parent;
	int		status;

	status = 0;
	pipe(fd);
	parent = fork();
	if (parent < 0)
		return (perror("Fork:	"));
	else if (!parent)
		ft_child_proc(fd, av, env);
	else
		ft_parent_proc(fd, av, env, status);
}

void	ft_child_proc(int *fd, char **av, char **env)
{
	int		fd_file_1;
	int		i;
	char	**paths;
	char	**cmds;
	char	*cmd;

	fd_file_1 = open(av[1], O_RDONLY);
	if (fd_file_1 == -1)
		return (perror("Pipex:	"));
	dup2(fd_file_1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd_file_1);
	paths = ft_paths(env);
	cmds = ft_cmds(av[2]);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], av[2]);
		execve(cmd, cmds, env);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	ft_parent_proc(int *fd, char **av, char **env, int status)
{
	int		fd_file_2;
	int		i;
	char	**paths;
	char	**cmds;
	char	*cmd;

	waitpid(-1, &status, 0);
	fd_file_2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_file_2 == -1)
		return (perror("Pipex:	"));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_file_2, STDOUT_FILENO);
	close(fd[1]);
	close(fd_file_2);
	paths = ft_paths(env);
	cmds = ft_cmds(av[3]);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], av[3]);
		execve(cmd, cmds, env);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}
