/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:45:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/10 14:45:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_prep(t_all *all)
{
	all->ray->drwheight = (int)(all->hres / all->ray->perpwall * all->asp);
	all->ray->drwstart = -all->ray->drwheight / 2 + all->hres / 2;
	if (all->ray->drwstart < 0)
		all->ray->drwstart = 0;
	all->ray->drwstop = all->ray->drwheight / 2 + all->hres / 2;
	if (all->ray->drwstop >= all->hres)
		all->ray->drwstop = all->hres - 1;
	if (all->ray->hside == 2 || all->ray->hside == 3)
		all->ray->wallx = all->ray->pposy + all->ray->perpwall *
											all->ray->raydiry;
	else
		all->ray->wallx = all->ray->pposx + all->ray->perpwall *
											all->ray->raydirx;
}

void	prep_north(t_all *all)
{
	all->ray->wallx -= floor(all->ray->wallx);
	all->ray->texx = (int)(all->ray->wallx * (double)all->tex->no->wi);
	if (all->ray->hside == 1 || all->ray->hside == 2)
		all->ray->texx = all->tex->no->wi - all->ray->texx - 1;
	all->ray->step = 1.0 * all->tex->no->he / all->ray->drwheight;
	all->ray->texpos = (all->ray->drwstart - all->hres / 2
			+ all->ray->drwheight / 2) * all->ray->step;
}

void	prep_west(t_all *all)
{
	all->ray->wallx -= floor(all->ray->wallx);
	all->ray->texx = (int)(all->ray->wallx * (double)all->tex->we->wi);
	if (all->ray->hside == 1 || all->ray->hside == 2)
		all->ray->texx = all->tex->we->wi - all->ray->texx - 1;
	all->ray->step = 1.0 * all->tex->we->he / all->ray->drwheight;
	all->ray->texpos = (all->ray->drwstart - all->hres / 2
			+ all->ray->drwheight / 2) * all->ray->step;
}

void	prep_east(t_all *all)
{
	all->ray->wallx -= floor(all->ray->wallx);
	all->ray->texx = (int)(all->ray->wallx * (double)all->tex->ea->wi);
	if (all->ray->hside == 1 || all->ray->hside == 2)
		all->ray->texx = all->tex->ea->wi - all->ray->texx - 1;
	all->ray->step = 1.0 * all->tex->ea->he / all->ray->drwheight;
	all->ray->texpos = (all->ray->drwstart - all->hres / 2
			+ all->ray->drwheight / 2) * all->ray->step;
}

void	prep_south(t_all *all)
{
	all->ray->wallx -= floor(all->ray->wallx);
	all->ray->texx = (int)(all->ray->wallx * (double)all->tex->so->wi);
	if (all->ray->hside == 1 || all->ray->hside == 2)
		all->ray->texx = all->tex->so->wi - all->ray->texx - 1;
	all->ray->step = 1.0 * all->tex->so->he / all->ray->drwheight;
	all->ray->texpos = (all->ray->drwstart - all->hres / 2
			+ all->ray->drwheight / 2) * all->ray->step;
}
