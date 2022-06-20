/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:51:47 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:44:33 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_buff_text(int fd, char *all_txt);
char	*ft_get_line(char *all_txt);
char	*ft_begining_next_buff_text(char	*all_txt);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all_txt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_txt = ft_get_buff_text(fd, all_txt);
	if (!all_txt)
		return (NULL);
	line = ft_get_line(all_txt);
	all_txt = ft_begining_next_buff_text(all_txt);
	return (line);
}

char	*ft_get_buff_text(int fd, char *all_txt)
{
	char	*nxt_line;
	int		rd;

	nxt_line = malloc(BUFFER_SIZE + 1);
	if (!nxt_line)
		return (NULL);
	rd = 1;
	while (!ft_strchr(all_txt, '\n') && rd)
	{
		rd = read(fd, nxt_line, BUFFER_SIZE);
		if (rd < 0)
		{
			free(nxt_line);
			return (NULL);
		}
		nxt_line[rd] = 0;
		if (!all_txt)
			all_txt = ft_newstr(all_txt);
		all_txt = ft_strjoin(all_txt, nxt_line);
	}
	free(nxt_line);
	return (all_txt);
}

char	*ft_get_line(char *all_txt)
{
	char	*memo_line;
	int		i;

	i = 0;
	if (!all_txt[i])
		return (NULL);
	while (all_txt[i] && all_txt[i] != '\n')
		i++;
	memo_line = malloc(i + 1 + 1);
	if (!memo_line)
		return (NULL);
	i = 0;
	while (all_txt[i] && all_txt[i] != '\n')
	{
		memo_line[i] = all_txt[i];
		i++;
	}
	if (all_txt[i] == '\n')
		memo_line[i++] = '\n';
	memo_line[i] = 0;
	return (memo_line);
}
//malloc(i + 1 + 1) == malloc(i + '\n' + '\0')

char	*ft_begining_next_buff_text(char	*all_txt)
{
	char	*next_beg;
	int		i;
	int		j;

	i = 0;
	while (all_txt[i] && all_txt[i] != '\n')
		i++;
	if (!all_txt[i])
	{
		free(all_txt);
		return (NULL);
	}
	next_beg = malloc(ft_strlen(all_txt) - i + 1);
	if (!next_beg)
		return (NULL);
	i++;
	j = 0;
	while (all_txt[i])
		next_beg[j++] = all_txt[i++];
	next_beg[j] = 0;
	free(all_txt);
	return (next_beg);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
