/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaiga <azouaiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:23:38 by azouaiga          #+#    #+#             */
/*   Updated: 2022/04/24 16:58:50 by azouaiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_checker(char c, va_list *ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(*ptr, int));
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		len += print_number(va_arg(*ptr, int));
	if (c == 'u')
		len += print_unb(va_arg(*ptr, unsigned int));
	if (c == 'x')
		len += print_hex(va_arg(*ptr, unsigned int), 1);
	if (c == 'X')
		len += print_hex(va_arg(*ptr, unsigned int), 2);
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_adr(va_arg(*ptr, unsigned long int));
	}
	if (c == 's')
		len += print_str(va_arg(*ptr, char *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_checker(format[i + 1], &ptr) + len;
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
