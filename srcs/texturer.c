/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:40:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/12 18:40:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_north(t_all *all, int x)
{
	all->ray->texy = (int)all->ray->texpos & (all->tex->no->he - 1);
	all->ray->texpos += all->ray->step;
	all->ray->rgb = (*(int*)(all->tex->no->addr
			+ ((all->ray->texx +
	(all->ray->texy * all->tex->no->wi)) * (all->tex->no->bpp / 8))));
	my_mlx_pixel_put(all, x, all->wline, all->ray->rgb);
}

void	draw_west(t_all *all, int x)
{
	all->ray->texy = (int)all->ray->texpos & (all->tex->we->he - 1);
	all->ray->texpos += all->ray->step;
	all->ray->rgb = (*(int*)(all->tex->we->addr
			+ ((all->ray->texx +
	(all->ray->texy * all->tex->we->wi)) * (all->tex->no->bpp / 8))));
	my_mlx_pixel_put(all, x, all->wline, all->ray->rgb);
}

void	draw_east(t_all *all, int x)
{
	all->ray->texy = (int)all->ray->texpos & (all->tex->ea->he - 1);
	all->ray->texpos += all->ray->step;
	all->ray->rgb = (*(int*)(all->tex->ea->addr
			+ ((all->ray->texx +
	(all->ray->texy * all->tex->ea->wi)) * (all->tex->no->bpp / 8))));
	my_mlx_pixel_put(all, x, all->wline, all->ray->rgb);
}

void	draw_south(t_all *all, int x)
{
	all->ray->texy = (int)all->ray->texpos & (all->tex->so->he - 1);
	all->ray->texpos += all->ray->step;
	all->ray->rgb = (*(int*)(all->tex->so->addr
			+ ((all->ray->texx +
	(all->ray->texy * all->tex->so->wi)) * (all->tex->no->bpp / 8))));
	my_mlx_pixel_put(all, x, all->wline, all->ray->rgb);
}
