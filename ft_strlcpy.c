/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaiga <azouaiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:54:33 by azouaiga          #+#    #+#             */
/*   Updated: 2022/04/24 16:57:21 by azouaiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlcpy(char *restrict dst, const char *restrict src,
		int dstsize)
{
	int		i;
	int		j;

	if (!src)
		return (0);
	j = 0;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (dstsize > 0)
	{
		while (src[j] != '\0' && j < (dstsize - 1))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}
