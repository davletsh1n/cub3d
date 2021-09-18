/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:25 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/02 15:20:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = malloc(len * sizeof(char));
	if (copy == NULL)
		return (NULL);
	else
		while (*s1 != '\0')
			*copy++ = *s1++;
	*copy = '\0';
	return (copy - len + 1);
}
