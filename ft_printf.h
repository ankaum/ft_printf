/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaiga <azouaiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:24:57 by azouaiga          #+#    #+#             */
/*   Updated: 2022/04/24 16:58:19 by azouaiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	print_number(int nb);
int	print_char(char c);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	print_adr(unsigned long int nb);
int	print_unb(unsigned int nb);
int	print_hex(unsigned int nb, int s);
int	print_str(char	*str);
int	ft_strlcpy(char *restrict dst, const char *restrict src, int dstsize);
#endif
