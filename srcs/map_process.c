/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:00:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/04 13:00:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_copy(t_all *all, int max)
{
	int i;
	int j;

	i = 0;
	while (i < all->maplen)
	{
		j = 0;
		all->map2[i] = ft_calloc(max, sizeof(char));
		while (all->map[i][j])
		{
			all->map2[i][j] = all->map[i][j];
			j++;
		}
		if (j < max)
		{
			while (j != max)
			{
				all->map2[i][j] = ' ';
				j++;
			}
		}
		i++;
	}
}

void	map_valid(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < all->maplen)
	{
		j = 0;
		while (j < all->maplon)
		{
			if (all->map2[i][j] == '0' || all->map2[i][j] == '2'
				|| all->map2[i][j] == 'N' || all->map2[i][j] == 'S'
				|| all->map2[i][j] == 'W' || all->map2[i][j] == 'E')
				!flood_fill(all, i, j) ? parse_errno(9) : 0;
			j++;
		}
		i++;
	}
}

void	get_sprites(t_all *all)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	all->sprites = ft_calloc(all->spnum, sizeof(t_sprpos));
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
			{
				all->sprites[x].x = j + 0.5;
				all->sprites[x].y = i + 0.5;
				x++;
			}
			j++;
		}
		i++;
	}
	map_valid(all);
}

void	map_process(t_all *all, t_vars *v)
{
	int i;
	int j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if ((all->map[i][j] == 'N' || all->map[i][j] == 'S'
				|| all->map[i][j] == 'W' || all->map[i][j] == 'E') && !v->plr)
				put_player(all, v, i, j);
			else if (all->map[i][j] == '2')
				all->spnum += 1;
			else if ((all->map[i][j] == 'N' || all->map[i][j] == 'S'
				|| all->map[i][j] == 'W' || all->map[i][j] == 'E') && v->plr)
				parse_errno(8);
			else if (!ft_strchr("012NSWE ", all->map[i][j]))
				parse_errno(13);
			j++;
		}
		i++;
	}
	!v->plr ? parse_errno(15) : 0;
	get_sprites(all);
}
