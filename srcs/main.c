/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:27:43 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/20 15:28:48 by ytoro-mo         ###   ########.fr       */
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
//system("leaks -q pipex");

void	ft_pipex(char **env, char **av)
{
	int		fd[2];
	pid_t	parent;

	pipe(fd);
	parent = fork();
	if (parent < 0)
		perror("Fork: ");
	else if (!parent)
		ft_child_proc(fd, av, env);
	else
	{
		parent = fork();
		if (parent < 0)
			perror("Fork: ");
		else if (!parent)
			ft_parent_proc(fd, av, env);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(parent, NULL, 0);
}

void	ft_child_proc(int *fd, char **av, char **env)
{
	int		fd_file_1;
	char	*path;
	char	**cmds;

	fd_file_1 = open(av[1], O_RDONLY);
	if (fd_file_1 == -1)
		return (perror("Pipex:	"));
	dup2(fd_file_1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd_file_1);
	cmds = ft_cmds(av[2]);
	path = ft_path_finder(ft_paths(env), cmds[0]);
	if (execve(path, cmds, env) == -1)
	{
		perror("Pipex: command not found");
		ft_free(cmds);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_parent_proc(int *fd, char **av, char **env)
{
	int		fd_file_2;
	char	*path;
	char	**cmds;

	fd_file_2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_file_2 == -1)
		return (perror("Pipex:	"));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_file_2, STDOUT_FILENO);
	close(fd[1]);
	close(fd_file_2);
	cmds = ft_cmds(av[3]);
	path = ft_path_finder(ft_paths(env), cmds[0]);
	if (execve(path, cmds, env) == -1)
	{
		perror("Pipex: command not found");
		ft_free(cmds);
		free(path);
		exit(EXIT_FAILURE);
	}
}
