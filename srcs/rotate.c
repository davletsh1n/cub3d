/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:15:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/03 18:15:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	look_left(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->ray->dirx;
	oldplanex = all->ray->planex;
	all->ray->dirx = all->ray->dirx * cos(-all->ray->rotspd)
		- all->ray->diry * sin(-all->ray->rotspd);
	all->ray->diry = olddirx * sin(-all->ray->rotspd)
		+ all->ray->diry * cos(-all->ray->rotspd);
	all->ray->planex = all->ray->planex * cos(-all->ray->rotspd)
		- all->ray->planey * sin(-all->ray->rotspd);
	all->ray->planey = oldplanex * sin(-all->ray->rotspd)
		+ all->ray->planey * cos(-all->ray->rotspd);
}

void	look_right(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->ray->dirx;
	oldplanex = all->ray->planex;
	all->ray->dirx = all->ray->dirx * cos(all->ray->rotspd)
		- all->ray->diry * sin(all->ray->rotspd);
	all->ray->diry = olddirx * sin(all->ray->rotspd)
		+ all->ray->diry * cos(all->ray->rotspd);
	all->ray->planex = all->ray->planex * cos(all->ray->rotspd)
		- all->ray->planey * sin(all->ray->rotspd);
	all->ray->planey = oldplanex * sin(all->ray->rotspd)
		+ all->ray->planey * cos(all->ray->rotspd);
}
