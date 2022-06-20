/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:42:31 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/25 16:46:58 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_wrds(const char *s, char c);
static char		*ft_putwrds(const char *s, size_t start, size_t end);

char	**ft_split(char const *s, char c)
{
	char	**wrds;
	size_t	i;
	size_t	j;
	int		start;

	wrds = malloc((ft_count_wrds(s, c) + 1) * sizeof(char *));
	if (!wrds || !s)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			wrds[j++] = ft_putwrds(s, start, i);
			start = -1;
		}
		i++;
	}
	wrds[j] = 0;
	return (wrds);
}

static size_t	ft_count_wrds(const char *s, char c)
{
	size_t	cnt_wrds;
	int		find;

	cnt_wrds = 0;
	find = 0;
	while (*s)
	{
		if (*s != c && !find)
		{
			cnt_wrds++;
			find = 1;
		}
		else if (*s == c)
			find = 0;
		s++;
	}
	return (cnt_wrds);
}

static char	*ft_putwrds(const char *s, size_t start, size_t end)
{
	char	*wrd;
	size_t	i;

	wrd = malloc((end - start + 1));
	i = 0;
	while (start < end)
		wrd[i++] = s[start++];
	wrd[i] = 0;
	return (wrd);
}
