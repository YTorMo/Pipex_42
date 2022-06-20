/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_formats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:46:53 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:40:08 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_int_format(int num)
{
	int			size;
	long		memo;

	memo = num;
	size = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		memo = -num;
		size++;
	}
	if (!memo)
		size++;
	while (memo)
	{
		memo /= 10;
		size++;
	}
	ft_to_num_print(num);
	return (size);
}

int	ft_unsigned_format(unsigned int num)
{
	int			size;
	long		memo;

	memo = num;
	size = 0;
	if (!memo)
		size++;
	while (memo)
	{
		memo /= 10;
		size++;
	}
	ft_to_num_print(num);
	return (size);
}

int	ft_low_hex_format(unsigned int num)
{
	int			size;
	uintptr_t	memo;

	memo = num;
	size = 0;
	if (!num)
	{
		ft_putchar_fd('0', 1);
		size++;
	}
	else
	{
		while (memo)
		{
			memo /= 16;
			size++;
		}
		ft_to_hex(num, 0);
	}
	return (size);
}

int	ft_up_hex_format(unsigned int num)
{
	int			size;
	uintptr_t	memo;

	memo = num;
	size = 0;
	if (!num)
	{
		ft_putchar_fd('0', 1);
		size++;
	}
	else
	{
		while (memo)
		{
			memo /= 16;
			size++;
		}
		ft_to_hex(num, 1);
	}
	return (size);
}
