/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:55:34 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/06 09:55:54 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? (char*)s2 : (char*)s1);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(len * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
		s3[i++] = *(s2++);
	s3[i] = '\0';
	return ((char*)s3);
}
