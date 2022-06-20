/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 08:26:58 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/20 15:19:53 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_paths(char **env)
{
	int		i;
	char	**path;
	char	*memo;

	i = 0;
	path = NULL;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	memo = &(env[i][5]);
	path = ft_split(memo, ':');
	i = -1;
	while (path[++i])
		path[i] = ft_strjoin(path[i], "/");
	return (path);
}

char	**ft_cmds(char *cmd_j)
{
	char	**cmds;

	cmds = ft_split(cmd_j, ' ');
	return (cmds);
}

char	*ft_path_finder(char **paths, char *cmd)
{
	char	*path;
	int		i;
	int		fd;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			ft_free(paths);
			close(fd);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
