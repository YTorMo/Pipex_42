/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:40:37 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/25 08:56:18 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*memo;
	size_t	len;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	while (len--)
	{
		*memo = *s1;
		memo++;
		s1++;
	}
	len = ft_strlen(s2);
	while (len--)
	{
		*memo = *s2;
		memo++;
		s2++;
	}
	*memo = 0;
	return (join);
}
