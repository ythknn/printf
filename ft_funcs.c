/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yihakan <yihakan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:26:05 by yihakan           #+#    #+#             */
/*   Updated: 2024/11/09 11:04:04 by yihakan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_funcs(size_t num, char *s, int flag, int s_len)
{
	int	len;

	len = 0;
	if (flag == 3)
	{
		if (!s)
			return (write(1, "(null)", 6));
		while (*s)
			len += write(1, s++, 1);
		return (len);
	}
	if (flag == 1)
	{
		if (num == 0)
			return (write(1, "(nil)", 5));
		len = write(1, "0x", 2);
	}
	if ((int)num < 0 && flag == 2)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	if (num >= (size_t)s_len)
		len += ft_funcs(num / s_len, s, 0, s_len);
	return (len + write(1, &s[num % s_len], 1));
}
