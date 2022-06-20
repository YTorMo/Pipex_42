/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:12:34 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/06/17 10:40:22 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_to_hex(uintptr_t num, int up)
{
	if (num >= 16)
	{
		ft_to_hex(num / 16, up);
		ft_to_hex(num % 16, up);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (!up)
				ft_putchar_fd((num - 10 + 'a'), 1);
			else
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

void	ft_to_num_print(long num)
{
	if (num < 0)
		num = -num;
	if (num >= 10)
	{
		ft_to_num_print(num / 10);
		ft_to_num_print(num % 10);
	}
	else
	{
		ft_putchar_fd((num + '0'), 1);
	}
}
