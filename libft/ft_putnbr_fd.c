/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:48:35 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/25 16:46:43 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_exp(int i);
static void	ft_numb_to_char(long nb, int pos_neg, int fb);

void	ft_putnbr_fd(int n, int fd)
{
	char	number;
	long	long_nb;

	long_nb = n;
	if (long_nb == 0)
	{
		number = '0';
		write(fd, &number, 1);
	}
	else if (n < 0)
	{
		long_nb = long_nb * (-1);
		ft_numb_to_char(long_nb, 0, fd);
	}
	else
	{
		ft_numb_to_char(long_nb, 1, fd);
	}
}

static int	ft_exp(int i)
{
	int	exp_10;

	exp_10 = 1;
	while (i > 0)
	{
		exp_10 = exp_10 * 10;
		i--;
	}
	return (exp_10);
}

static void	ft_numb_to_char(long nb, int pos_neg, int fd)
{
	int		i;
	long	exp_nb;
	long	nb_2;
	char	number;

	nb_2 = nb;
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (pos_neg == 0)
	{
		number = '-';
		write(fd, &number, 1);
	}
	while (i > 0)
	{
		exp_nb = ft_exp(i - 1);
		number = (nb_2 / exp_nb) + 48;
		nb_2 = nb_2 - ((nb_2 / exp_nb) * exp_nb);
		write(fd, &number, 1);
		i--;
	}
}
