/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:37:06 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/06 10:06:22 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;
	char	*str;
	int		len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char*)s1);
	head = (char*)s1;
	tail = (char*)s1 + ft_strlen(s1);
	while (*head && ft_strchr(set, *head))
		head++;
	while (head != tail && ft_strchr(set, *(tail - 1)))
		tail--;
	len = (tail - head);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, head, (size_t)len + 1);
	return (str);
}
