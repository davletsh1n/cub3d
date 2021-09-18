/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:10:50 by ssandman          #+#    #+#             */
/*   Updated: 2020/10/31 16:04:37 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*todo;

	todo = b;
	i = 0;
	while (i < len)
	{
		*todo++ = (unsigned char)c;
		i++;
	}
	return (b);
}
