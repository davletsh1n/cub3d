/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:15:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/05 12:15:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/cub3d.h"

void	parsestart(t_all *all, t_vars *v, int fd, t_list *head)
{
	while (fd && !v->map)
	{
		if (((char*)(head->content))[0] != '\0')
			check_id(all, head, v);
		head = head->next;
		fd--;
	}
}

void	get_wi(int i, t_list *head, t_all *all)
{
	if (ascii_numlen(((char*)(head->content)) + i) > 5 && all->shoot == 1)
		parse_errno(17);
	else if (ascii_numlen(((char*)(head->content)) + i) > 5 && !all->shoot)
		all->wres = 16384;
	else
		all->wres = ft_atoi(((char*)(head->content)) + i);
	if (all->wres > 16384 && all->shoot == 1)
		parse_errno(17);
}

void	get_hi(int i, t_list *head, t_all *all)
{
	if (ascii_numlen(((char*)(head->content)) + i) > 5 && all->shoot == 1)
		parse_errno(17);
	else if (ascii_numlen(((char*)(head->content)) + i) > 5 && !all->shoot)
		all->hres = 16384;
	else
		all->hres = ft_atoi(((char*)(head->content)) + i);
	if (all->hres > 16384 && all->shoot == 1)
		parse_errno(17);
}

void	aspect_fix(t_all *all)
{
	double w;
	double h;

	w = all->wres;
	h = all->hres;
	h /= w;
	all->asp = 0.75 / h;
}

void	get_garbage(char *line, int i)
{
	while (line[i] != '\0')
	{
		line[i] != ' ' ? parse_errno(4) : 0;
		i++;
	}
}
