/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:57:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/03 18:57:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_vars(t_vars *vars)
{
	vars->re = 0;
	vars->no = 0;
	vars->so = 0;
	vars->we = 0;
	vars->ea = 0;
	vars->sp = 0;
	vars->fl = 0;
	vars->ce = 0;
	vars->map = 0;
	vars->plr = 0;
}

void	init_rays(t_all *all)
{
	all->ray->dirx = 0;
	all->ray->diry = 0;
	all->ray->planex = 0;
	all->ray->planey = 0;
	all->ray->rotspd = 0.1;
	all->ray->mvspd = 0.1;
	all->spnum = 0;
	all->shoot = 0;
}

void	init_textures(t_all *all)
{
	t_img *north;
	t_img *south;
	t_img *west;
	t_img *east;
	t_img *sprite;

	if (!(north = ft_calloc(1, sizeof(t_img))))
		parse_errno(10);
	if (!(south = ft_calloc(1, sizeof(t_img))))
		parse_errno(10);
	if (!(west = ft_calloc(1, sizeof(t_img))))
		parse_errno(10);
	if (!(east = ft_calloc(1, sizeof(t_img))))
		parse_errno(10);
	if (!(sprite = ft_calloc(1, sizeof(t_img))))
		parse_errno(10);
	all->tex->no = north;
	all->tex->so = south;
	all->tex->we = west;
	all->tex->ea = east;
	all->tex->sprt = sprite;
}
