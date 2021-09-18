/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:12:03 by ssandman          #+#    #+#             */
/*   Updated: 2020/10/31 17:21:19 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char*)dest;
	from = (unsigned char*)src;
	while (n--)
	{
		if (*from == (unsigned char)c)
		{
			*to = *from;
			return (to + 1);
		}
		*to++ = *from++;
	}
	return (NULL);
}
