/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/25 08:55:45 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*lasts;
	char		*lastd;

	d = dst;
	s = src;
	if (!d && !s)
		return (NULL);
	if (len != 0 || dst != src)
	{
		if (d < s)
		{
			while (len--)
				*d++ = *s++;
		}
		else
		{
			lasts = (char *)s + (len - 1);
			lastd = d + (len - 1);
			while (len--)
				*lastd-- = *lasts--;
		}
	}
	return (dst);
}
