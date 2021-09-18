/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:48:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/09 14:48:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		raycast(t_all *all)
{
	int x;

	x = 0;
	while (x < all->wres)
	{
		dda_init(all, x);
		dda_stepinit(all);
		dda_loop(all);
		draw_prep(all);
		sides_prep(all);
		draw_ceiling(all, x);
		while (all->wline < all->ray->drwstop)
			draw_wall(all, x);
		draw_floor(all, x);
		all->zb[x] = all->ray->perpwall;
		x++;
	}
	spriter(all);
	if (!all->shoot)
		mlx_put_image_to_window(all->win->mlx, all->win->win,
			all->win->img, 0, 0);
	return (0);
}

void	put_player(t_all *all, t_vars *v, int i, int j)
{
	v->plr = 1;
	all->ray->pposx = j + 0.5;
	all->ray->pposy = i + 0.5;
	if ((char)all->map[i][j] == 'E')
	{
		all->ray->dirx = 1;
		all->ray->planey = tan(M_PI * 66 / 360);
	}
	if ((char)all->map[i][j] == 'W')
	{
		all->ray->dirx = -1;
		all->ray->planey = -tan(M_PI * 66 / 360);
	}
	if ((char)all->map[i][j] == 'N')
	{
		all->ray->planex = tan(M_PI * 66 / 360);
		all->ray->diry = -1;
	}
	if ((char)all->map[i][j] == 'S')
	{
		all->ray->diry = 1;
		all->ray->planex = -tan(M_PI * 66 / 360);
	}
	all->map[i][j] = '0';
}

void	dda_init(t_all *all, int x)
{
	all->ray->camx = 2 * x / (double)all->wres - 1;
	all->ray->raydirx = all->ray->dirx + all->ray->planex * all->ray->camx;
	all->ray->raydiry = all->ray->diry + all->ray->planey * all->ray->camx;
	all->ray->mapx = (int)all->ray->pposx;
	all->ray->mapy = (int)all->ray->pposy;
	all->ray->ddistx = fabs(1 / all->ray->raydirx);
	all->ray->ddisty = fabs(1 / all->ray->raydiry);
	all->ray->hit = 0;
	all->wline = 0;
}

void	dda_stepinit(t_all *all)
{
	if (all->ray->raydirx < 0)
	{
		all->ray->stepx = -1;
		all->ray->sdistx = (all->ray->pposx
				- all->ray->mapx) * all->ray->ddistx;
	}
	else
	{
		all->ray->stepx = 1;
		all->ray->sdistx = (1.0 + all->ray->mapx
				- all->ray->pposx) * all->ray->ddistx;
	}
	if (all->ray->raydiry < 0)
	{
		all->ray->stepy = -1;
		all->ray->sdisty = (all->ray->pposy
				- all->ray->mapy) * all->ray->ddisty;
	}
	else
	{
		all->ray->stepy = 1;
		all->ray->sdisty = (1.0 + all->ray->mapy
				- all->ray->pposy) * all->ray->ddisty;
	}
}

void	dda_loop(t_all *all)
{
	while (all->ray->hit == 0)
	{
		if (all->ray->sdistx <= all->ray->sdisty)
		{
			all->ray->sdistx += all->ray->ddistx;
			all->ray->mapx += all->ray->stepx;
			all->ray->hside = all->ray->raydirx < 0 ? 2 : 3;
		}
		else
		{
			all->ray->sdisty += all->ray->ddisty;
			all->ray->mapy += all->ray->stepy;
			all->ray->hside = all->ray->raydiry < 0 ? 0 : 1;
		}
		if (all->map[all->ray->mapy][all->ray->mapx] == '1')
			all->ray->hit = 1;
	}
	if (all->ray->hside > 1)
		all->ray->perpwall = (all->ray->mapx - all->ray->pposx +
		(1 - all->ray->stepx) / 2) / all->ray->raydirx;
	else
		all->ray->perpwall = (all->ray->mapy - all->ray->pposy +
		(1 - all->ray->stepy) / 2) / all->ray->raydiry;
}
