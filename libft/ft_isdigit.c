/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:17:40 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/20 12:13:13 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main(void)
{
	if(ft_isdigit(49))
		printf("Es un caracter numerico");
	else
		printf("No es un caracter numerico");
	return(0);
}*/