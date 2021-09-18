/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:05:30 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/01 16:22:52 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*look;
	size_t			found;

	found = 0;
	look = (unsigned char*)s;
	while (n--)
	{
		if (*look == (unsigned char)c)
		{
			found = 1;
			break ;
		}
		look++;
	}
	return ((found == 1) ? look : NULL);
}
