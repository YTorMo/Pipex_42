/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:25:48 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/20 15:21:30 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	**ft_paths(char **env);
char	**ft_cmds(char *cmd_j);
void	ft_pipex(char **env, char **av);
void	ft_child_proc(int *fd, char **av, char **env);
void	ft_parent_proc(int *fd, char **av, char **env);
void	ft_free(char **txt);
char	*ft_path_finder(char **paths, char *cmd);

#endif