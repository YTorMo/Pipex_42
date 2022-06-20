/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:00:03 by Yago_42           #+#    #+#             */
/*   Updated: 2022/06/17 10:40:27 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	int		print_size;
	int		i;
	va_list	input;

	va_start(input, str);
	print_size = 0;
	i = 0;
	if (ft_strchr(str, '%'))
		print_size = ft_replacement(str, input);
	else
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
			print_size++;
		}
	}
	va_end(input);
	return (print_size);
}

int	ft_replacement(const char *str, va_list input)
{
	int	i;
	int	print_size;

	i = 0;
	print_size = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar_fd(str[i++], 1);
			print_size++;
		}
		if (str[i])
		{
			i++;
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
				|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x'
				|| str[i] == 'X' || str[i] == '%')
				print_size += ft_percent_format(str[i], input);
			i++;
		}
	}
	return (print_size);
}

int	ft_percent_format(char c, va_list input)
{
	int	print_size;

	print_size = 0;
	if (c == 'c')
		print_size = ft_char_format(va_arg(input, int));
	else if (c == 's')
		print_size += ft_str_format(va_arg(input, char *));
	else if (c == 'p')
		print_size += ft_pointer_format(va_arg(input, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_size += ft_int_format(va_arg(input, int));
	else if (c == 'u')
		print_size += ft_unsigned_format(va_arg(input, unsigned int));
	else if (c == 'x')
		print_size += ft_low_hex_format(va_arg(input, unsigned int));
	else if (c == 'X')
		print_size += ft_up_hex_format(va_arg(input, unsigned int));
	else if (c == '%')
		print_size += ft_percentage_format();
	return (print_size);
}
