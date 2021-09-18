/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:06:51 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/01 15:58:31 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*to;
	char	*from;

	to = (char*)dest;
	from = (char*)src;
	if (to == from)
		return (dest);
	if (to < from)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			to[n - 1] = from[n - 1];
			n--;
		}
	}
	return (dest);
}
