/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:57:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/12 15:57:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall(t_all *all, int x)
{
	all->ray->hside == 0 ? draw_north(all, x) : 0;
	all->ray->hside == 1 ? draw_south(all, x) : 0;
	all->ray->hside == 2 ? draw_west(all, x) : 0;
	all->ray->hside == 3 ? draw_east(all, x) : 0;
	all->wline += 1;
}

void	draw_ceiling(t_all *all, int x)
{
	while (all->wline < all->ray->drwstart - 1)
	{
		my_mlx_pixel_put(all, x, all->wline, all->ceiling);
		all->wline += 1;
	}
}

void	draw_floor(t_all *all, int x)
{
	while (all->wline < all->hres)
	{
		my_mlx_pixel_put(all, x, all->wline, all->floor);
		all->wline += 1;
	}
}
