/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:24:21 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/06 13:08:52 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		slen(int n)
{
	int		i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*ascii;

	i = slen(n);
	if (!(ascii = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	ascii[i] = '\0';
	if (n == 0)
		ascii[0] = '0';
	if (n < 0)
	{
		ascii[0] = '-';
		ascii[--i] = n % 10 * (-1) + '0';
		n /= 10 * (-1);
	}
	while (n != 0)
	{
		ascii[--i] = n % 10 + '0';
		n /= 10;
	}
	return (ascii);
}
