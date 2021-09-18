/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:26:27 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/03 19:54:24 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	if (*needle == '\0')
		return ((char*)haystack);
	n = ft_strlen(needle);
	while (*haystack && n <= len--)
	{
		if (ft_strncmp(haystack, needle, n) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
