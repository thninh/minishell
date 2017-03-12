/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:18:14 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 17:49:57 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_which_letter(const char *format, int i, va_list ap)
{
	if (format[i] == 's')
		ft_putstr(va_arg(ap, char*));
	else if (format[i] == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (format[i] == 'c')
		ft_putchar(va_arg(ap, int));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_which_letter(format, i, ap);
			i++;
		}
		while ((format[i] != '%') && (format[i]))
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
