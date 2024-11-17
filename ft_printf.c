/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihakan <yihakan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:17:53 by yihakan           #+#    #+#             */
/*   Updated: 2024/11/10 03:04:34 by yihakan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{
	int	char_flag;

	if (c == 'c')
	{
		char_flag = va_arg(args, int);
		return (write(1, &char_flag, 1));
	}
	else if (c == 's')
		return (ft_funcs(0, va_arg(args, char *), 3, 0));
	else if (c == 'p')
		return (ft_funcs(va_arg(args, unsigned long), \
		"0123456789abcdef", 1, 16));
	else if (c == 'd' || c == 'i')
		return (ft_funcs(va_arg(args, int), "0123456789", 2, 10));
	else if (c == 'u')
		return (ft_funcs(va_arg(args, unsigned), "0123456789", 0, 10));
	else if (c == 'x')
		return (ft_funcs(va_arg(args, unsigned), "0123456789abcdef", 0, 16));
	else if (c == 'X')
		return (ft_funcs(va_arg(args, unsigned), "0123456789ABCDEF", 0, 16));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	a;

	va_start(a, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[++i] == ' ')
				;
			len += ft_check(str[i], a);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}
