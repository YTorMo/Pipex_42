/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:53:38 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/25 08:56:23 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len > dstsize)
		return (src_len + dstsize);
	while (*src != '\0' && dstsize-- > (dst_len + 1))
	{
		dst[dst_len + i] = *src;
		i++;
		src++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
