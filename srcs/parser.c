/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:42:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/04 12:42:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/cub3d.h"

void	clearlist(t_list *oldhead)
{
	t_list *tmp;

	while (oldhead)
	{
		tmp = oldhead;
		oldhead = oldhead->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	free(oldhead);
}

void	mapper(t_all *all, t_list *head, t_vars *v)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	v->map = 1;
	all->maplen = ft_lstsize(head);
	all->map = ft_calloc(all->maplen + 1, sizeof(char*));
	all->map2 = ft_calloc(all->maplen + 1, sizeof(char*));
	while (head)
	{
		all->map[i] = ft_strdup(head->content);
		head = head->next;
		max = max < (int)ft_strlen(all->map[i])
				? (int)ft_strlen(all->map[i]) : max;
		i++;
	}
	all->maplon = max;
	map_copy(all, max);
	map_process(all, v);
}

int		check_params(t_vars *v)
{
	return ((v->re && v->no && v->so && v->we && v->ea
		&& v->sp && v->fl && v->ce) ? 1 : 0);
}

void	check_id(t_all *all, t_list *head, t_vars *v)
{
	if (!ft_memcmp((char*)head->content, "R ", 2) && !v->re)
		get_res(all, head, v);
	else if (!ft_memcmp((char*)head->content, "NO ", 3) && !v->no)
		get_north(all, (char*)(head->content) + 2, v);
	else if (!ft_memcmp((char*)head->content, "SO ", 3) && !v->so)
		get_south(all, (char*)(head->content) + 2, v);
	else if (!ft_memcmp((char*)head->content, "WE ", 3) && !v->we)
		get_west(all, (char*)(head->content) + 2, v);
	else if (!ft_memcmp((char*)head->content, "EA ", 3) && !v->ea)
		get_east(all, (char*)(head->content) + 2, v);
	else if (!ft_memcmp((char*)head->content, "S ", 2) && !v->sp)
		get_sprite(all, (char*)(head->content) + 1, v);
	else if (!ft_memcmp((char*)head->content, "F ", 2) && !v->fl)
		get_floor(all, (char*)(head->content) + 1, v);
	else if (!ft_memcmp((char*)head->content, "C ", 2) && !v->ce)
		get_ceiling(all, (char*)(head->content) + 1, v);
	else if ((!ft_memcmp((char*)head->content, " ", 1)
		|| !ft_memcmp((char*)head->content, "1", 1)))
		check_params(v) ? mapper(all, head, v) : parse_errno(12);
	else
		parse_errno(2);
}

void	parse_file(char **av, t_all *all)
{
	int		fd;
	char	*line;
	t_list	*head;
	t_list	*tmp;
	t_vars	v;

	init_vars(&v);
	line = NULL;
	head = NULL;
	fd = open(av[1], O_RDONLY);
	read(fd, NULL, 0) < 0 ? parse_errno(16) : 0;
	fd < 0 ? parse_errno(14) : fd;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	fd = 0;
	fd = ft_lstsize(head);
	tmp = head;
	parsestart(all, &v, fd, head);
	aspect_fix(all);
	clearlist(tmp);
}
