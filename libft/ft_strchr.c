/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:06:17 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/20 16:34:17 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*occur;

	while (*s != '\0')
	{
		if ((char)*s == (char)c)
		{
			occur = (char *)s;
			return (occur);
		}
		s++;
	}
	if (c == 0)
		return (occur = (char *)s);
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[20]= "Estoy hola muchas h";
	printf("%s", ft_strchr(str, 122));
	return (0);
}*/