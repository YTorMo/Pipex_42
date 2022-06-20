/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:08:34 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/20 17:56:59 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	j = 0;
	while (i < len && haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] != '\0' && haystack[j + i] != '\0'
			&& needle[i] == haystack[j + i] && i + j < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char str[50] = "Estoy probando los needles en strnstr";
	printf("%s", ft_strnstr(str, "l", 3));
	return (0);
} */
