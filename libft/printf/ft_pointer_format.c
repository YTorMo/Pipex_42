/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:29:12 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:40:17 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_pointer_format(uintptr_t ptr)
{
	int			size;
	uintptr_t	num;

	num = ptr;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	size = 2;
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		size++;
	}
	else
	{
		while (ptr)
		{
			ptr /= 16;
			size++;
		}
		ft_to_hex(num, 0);
	}
	return (size);
}
