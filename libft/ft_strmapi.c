/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:44:29 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/22 10:57:42 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	mapi = malloc(ft_strlen(s) + 1);
	if (!mapi || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		mapi[i] = f(i, *s);
		i++;
		s++;
	}
	mapi[i] = 0;
	return (mapi);
}
