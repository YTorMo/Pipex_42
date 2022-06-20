/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:20:02 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/20 16:19:24 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*occur;
	int		i;

	i = 0;
	occur = (void *)s;
	while (n--)
	{
		if (*(char *)occur == (char)c)
			return (occur);
		occur++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[20]= "Estoy hola muchas h";
	printf("%s", ft_memchr(str, 104, 5));
	return (0);
}*/