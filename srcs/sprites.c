/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:19:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/03 12:19:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sprite_dist(t_all *all)
{
	int ac;
	int bc;
	int i;

	i = 0;
	while (i < all->spnum)
	{
		ac = all->ray->pposx - all->sprites[i].x;
		bc = all->ray->pposy - all->sprites[i].y;
		all->sprites[i].d = sqrt(pow(ac, 2) + pow(bc, 2));
		i++;
	}
}

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprpos	temp;

	i = 0;
	j = 0;
	sprite_dist(all);
	while (i < all->spnum)
	{
		j = 0;
		while (j < all->spnum - 1)
		{
			if (all->sprites[j].d < all->sprites[j + 1].d)
			{
				temp = all->sprites[j];
				all->sprites[j] = all->sprites[j + 1];
				all->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
