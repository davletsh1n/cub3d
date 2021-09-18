/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:36:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/09 14:36:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->win->addr + (y * all->win->line_l + x * (all->win->bpp / 8));
	*(unsigned int*)dst = color;
}

int		numlen(int num)
{
	if (num < 0)
		return (1 + numlen(-num));
	else if (num < 10)
		return (1);
	else
		return (1 + numlen(num / 10));
}

int		count_spaces(const char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int		flood_fill(t_all *all, int i, int j)
{
	if (i < 0 || j < 0 || i > all->maplen)
		return (0);
	if (all->map2[i] == NULL)
		return (0);
	if (all->map2[i][j] == ' ' || all->map2[i][j] == '\0')
		return (0);
	if (all->map2[i][j] == '1' || all->map2[i][j] == 'x')
		return (1);
	all->map2[i][j] = 'x';
	return (flood_fill(all, i + 1, j) && flood_fill(all, i - 1, j)
			&& flood_fill(all, i, j + 1) && flood_fill(all, i, j - 1));
}

void	sides_prep(t_all *all)
{
	all->ray->wallx -= floor(all->ray->wallx);
	all->ray->hside == 0 ? prep_north(all) : 0;
	all->ray->hside == 1 ? prep_south(all) : 0;
	all->ray->hside == 2 ? prep_west(all) : 0;
	all->ray->hside == 3 ? prep_east(all) : 0;
	if (all->ray->hside == 2 || all->ray->hside == 3)
		all->ray->wallx = all->ray->pposy
			+ all->ray->perpwall * all->ray->raydiry;
	else
		all->ray->wallx = all->ray->pposx
			+ all->ray->perpwall * all->ray->raydiry;
}
