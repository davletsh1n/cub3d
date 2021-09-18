/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:43:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/03 18:43:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	deal_key(int key, t_all *all)
{
	key == ESC ? exit(0) : key;
	if (key == W || key == UARR)
		move_forward(all);
	if (key == S || key == DARR)
		move_back(all);
	if (key == LARR)
		look_left(all);
	if (key == RARR)
		look_right(all);
	if (key == A)
		move_left(all);
	if (key == D)
		move_right(all);
	raycast(all);
	return (0);
}
