/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:31:48 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/03 21:19:29 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (i < n && p1[i] == p2[i])
		i++;
	return ((i == n ? 0 : (p1[i] - p2[i])));
}
