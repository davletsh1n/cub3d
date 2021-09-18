/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:06:55 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/03 16:23:37 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	j = i;
	while (src[i - j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src) + j);
}
