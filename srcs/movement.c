/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:59:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/15 14:59:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_all *all)
{
	if (all->map[(int)all->ray->pposy][(int)(all->ray->pposx
		+ all->ray->dirx * 0.5)] == '0')
		all->ray->pposx += all->ray->dirx * all->ray->mvspd;
	if (all->map[(int)(all->ray->pposy + all->ray->diry * 0.5)]
		[(int)all->ray->pposx] == '0')
		all->ray->pposy += all->ray->diry * all->ray->mvspd;
}

void	move_back(t_all *all)
{
	if (all->map[(int)all->ray->pposy][(int)(all->ray->pposx
		- all->ray->dirx * 0.5)] == '0')
		all->ray->pposx -= all->ray->dirx * all->ray->mvspd;
	if (all->map[(int)(all->ray->pposy - all->ray->diry * 0.5)]
	[(int)all->ray->pposx] == '0')
		all->ray->pposy -= all->ray->diry * all->ray->mvspd;
}

void	move_left(t_all *all)
{
	if ((all->map[(int)all->ray->pposy][(int)(all->ray->pposx
		- all->ray->planex * 0.11)]) == '0')
		all->ray->pposx -= all->ray->planex * all->ray->mvspd;
	if ((all->map[(int)(all->ray->pposy - all->ray->planey * 0.11)]
		[(int)all->ray->pposx]) == '0')
		all->ray->pposy -= all->ray->planey * all->ray->mvspd;
}

void	move_right(t_all *all)
{
	if ((all->map[(int)all->ray->pposy][(int)(all->ray->pposx
		+ all->ray->planex * 0.11)]) == '0')
		all->ray->pposx += all->ray->planex * all->ray->mvspd;
	if ((all->map[(int)(all->ray->pposy + all->ray->planey * 0.11)]
	[(int)all->ray->pposx]) == '0')
		all->ray->pposy += all->ray->planey * all->ray->mvspd;
}
