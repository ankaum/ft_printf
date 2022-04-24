/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaiga <azouaiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:25:44 by azouaiga          #+#    #+#             */
/*   Updated: 2022/04/24 16:58:50 by azouaiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_number(n / 10);
		len += print_number(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

int	print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_adr(nb / 16);
		len += print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
			len += print_char(nb + 87);
	}
	return (len);
}

int	print_unb(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unb(nb / 10);
		len += print_unb(nb % 10);
	}
	if (nb < 10)
		len += print_char(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int		len;
	char	base_min[17];
	char	base_maj[17];

	ft_strlcpy(base_min, "0123456789abcdef", 17);
	ft_strlcpy(base_maj, "0123456789ABCDEF", 17);
	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	else
	{
		if (s == 2)
			len += print_char(base_maj[nb]);
		else if (s == 1)
			len += print_char(base_min[nb]);
	}
	return (len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
