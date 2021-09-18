/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:24:42 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/01 13:47:43 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *to;
	char *from;

	if (dst == NULL && src == NULL)
		return (NULL);
	to = (char*)dst;
	from = (char*)src;
	while (n--)
		*to++ = *from++;
	return (dst);
}
