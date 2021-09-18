/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:17:01 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/07 19:55:42 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *begin;
	t_list *tonext;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		tonext = begin->next;
		del(begin->content);
		free(begin);
		begin = tonext;
	}
	*lst = NULL;
}
