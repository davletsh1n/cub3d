/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:58:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/23 15:58:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/cub3d.h"

int		ascii_numlen(char *line)
{
	int i;

	i = 0;
	if (line[i] == '-' && ft_isdigit(line[i + 1]))
		i++;
	while (ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	return (i);
}

void	get_ceiling(t_all *all, char *line, t_vars *v)
{
	int i;

	i = 0;
	i += count_spaces(line + i);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fr = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fr);
	line[i] == ',' ? i++ : parse_errno(7);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fg = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fg);
	line[i] == ',' ? i++ : parse_errno(7);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fb = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fb);
	get_garbage(line, i);
	(all->fr > 255) || (all->fr < 0) ? parse_errno(7) : 0;
	(all->fg > 255) || (all->fg < 0) ? parse_errno(7) : 0;
	(all->fb > 255) || (all->fb < 0) ? parse_errno(7) : 0;
	all->ceiling = (0 << 24 | all->fr << 16 | all->fg << 8 | all->fb);
	v->ce = 1;
}

void	get_floor(t_all *all, char *line, t_vars *v)
{
	int i;

	i = 0;
	i += count_spaces(line + i);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fr = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fr);
	line[i] == ',' ? i++ : parse_errno(7);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fg = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fg);
	line[i] == ',' ? i++ : parse_errno(7);
	(ft_isdigit(line[i]) && ascii_numlen(line + i) <= 3) ?
			all->fb = ft_atoi(line + i) : parse_errno(7);
	i += numlen(all->fb);
	get_garbage(line, i);
	(all->fr > 255) || (all->fr < 0) ? parse_errno(7) : 0;
	(all->fg > 255) || (all->fg < 0) ? parse_errno(7) : 0;
	(all->fb > 255) || (all->fb < 0) ? parse_errno(7) : 0;
	all->floor = (0 << 24 | all->fr << 16 | all->fg << 8 | all->fb);
	v->fl = 1;
}

void	check_res(t_all *all)
{
	int max_w;
	int max_h;

	mlx_get_screen_size(all->win->mlx, &max_w, &max_h);
	if (all->wres < 32 || all->hres < 32)
		parse_errno(18);
	if (all->wres > max_w && all->shoot == 0)
		all->wres = max_w;
	if (all->hres > max_h && all->shoot == 0)
		all->hres = max_h;
	if (all->wres > 16384 && all->shoot == 1)
		all->wres = 16384;
	if (all->hres > 16384 && all->shoot == 1)
		all->hres = 16384;
}

void	get_res(t_all *all, t_list *head, t_vars *v)
{
	int i;

	i = 1;
	i += count_spaces(((char*)(head->content)) + i);
	if (ft_isdigit(((char*)(head->content))[i]))
		get_wi(i, head, all);
	else
		parse_errno(3);
	i += ascii_numlen(((char*)(head->content)) + i);
	i += count_spaces(((char*)(head->content)) + i);
	if (ft_isdigit(((char*)(head->content))[i]))
		get_hi(i, head, all);
	else
		parse_errno(3);
	check_res(all);
	i += ascii_numlen(((char*)(head->content)) + i);
	i += count_spaces(((char*)(head->content)) + i);
	((char*)(head->content))[i] == '\0' ? v->re = 1 : parse_errno(4);
	if (!(all->zb = ft_calloc(all->wres, sizeof(double))))
		parse_errno(10);
}
