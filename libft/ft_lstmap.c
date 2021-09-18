/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:55:48 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/07 21:23:20 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *step;
	t_list *begin;

	if (!lst || !f || !(step = ft_lstnew(f(lst->content))))
		return (NULL);
	begin = step;
	while (lst->next)
	{
		lst = lst->next;
		if (!(step->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		step = step->next;
	}
	return (begin);
}
