/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 08:26:58 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/20 11:40:19 by ytoro-mo         ###   ########.fr       */
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
