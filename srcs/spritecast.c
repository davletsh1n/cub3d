/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:15:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/04 14:15:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_sprite(t_all *all, int i)
{
	all->ray->sprtx = all->sprites[i].x - all->ray->pposx;
	all->ray->sprty = all->sprites[i].y - all->ray->pposy;
	all->ray->invdet = 1.0 / (all->ray->planex * all->ray->diry
		- all->ray->dirx * all->ray->planey);
	all->ray->trnx = all->ray->invdet * (all->ray->diry
		* all->ray->sprtx - all->ray->dirx * all->ray->sprty);
	all->ray->trny = all->ray->invdet * (-all->ray->planey
		* all->ray->sprtx + all->ray->planex * all->ray->sprty);
	all->ray->sscrx = (int)((all->wres / 2)
		* (1 + all->ray->trnx / all->ray->trny));
	all->ray->spr_he = fabs((all->hres / (all->ray->trny))) * all->asp - 1;
	all->ray->drwstrt_y = -all->ray->spr_he / 2 + all->hres / 2;
	(all->ray->drwstrt_y < 0) ? all->ray->drwstrt_y = 0 : 0;
	all->ray->drwend_y = all->ray->spr_he / 2 + all->hres / 2;
	(all->ray->drwend_y >= all->hres) ? all->ray->drwend_y = all->hres - 1 : 0;
	all->ray->spr_wi = fabs((all->hres / (all->ray->trny))) * all->asp;
	all->ray->drwstrt_x = -all->ray->spr_wi / 2 + all->ray->sscrx + 1;
	(all->ray->drwstrt_x < 0) ? all->ray->drwstrt_x = 0 : 0;
	all->ray->drwend_x = all->ray->spr_wi / 2 + all->ray->sscrx + 1;
	(all->ray->drwend_x >= all->wres) ? all->ray->drwend_x = all->wres - 1 : 0;
}

void	draw_sprite(t_all *all, int stripe)
{
	int tx;
	int ty;
	int j;
	int d;

	while (stripe < all->ray->drwend_x)
	{
		tx = (int)(256 * (stripe - (-all->ray->spr_wi / 2 + all->ray->sscrx))
			* all->tex->sprt->wi / all->ray->spr_wi) / 256;
		if (all->ray->trny > 0 && stripe > 0 && stripe < all->wres
			&& all->ray->trny < all->zb[stripe])
		{
			j = all->ray->drwstrt_y;
			while (j++ < all->ray->drwend_y)
			{
				d = (j) * 256 - all->hres * 128 + all->ray->spr_he * 128;
				ty = ((d * all->tex->sprt->he) / all->ray->spr_he) / 256;
				all->ray->rgb = (*(int*)(all->tex->sprt->addr + (tx + (ty
					* all->tex->sprt->wi)) * (all->tex->no->bpp / 8)));
				all->ray->rgb != (int)0xFF000000
				? my_mlx_pixel_put(all, stripe, j, all->ray->rgb) : 0;
			}
		}
		stripe++;
	}
}

void	spriter(t_all *all)
{
	int i;
	int stripe;

	i = 0;
	sort_sprites(all);
	while (i < all->spnum)
	{
		calc_sprite(all, i);
		stripe = all->ray->drwstrt_x;
		draw_sprite(all, stripe);
		i++;
	}
}
