/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:13:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/03 12:13:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_errno(int err)
{
	ft_putendl_fd("Error", 2);
	err == 1 ? ft_putendl_fd("wrong identifier", 2) : 0;
	err == 2 ? ft_putendl_fd("identifier error", 2) : 0;
	err == 3 ? ft_putendl_fd("wrong resolution", 2) : 0;
	err == 4 ? ft_putendl_fd("garbage in a line", 2) : 0;
	err == 5 ? ft_putendl_fd("duplicated identifer", 2) : 0;
	err == 6 ? ft_putendl_fd("bad texture", 2) : 0;
	err == 7 ? ft_putendl_fd("wrong color", 2) : 0;
	err == 8 ? ft_putendl_fd("more than 1 plr on a map", 2) : 0;
	err == 9 ? ft_putendl_fd("map invalid, floodfill failure", 2) : 0;
	err == 10 ? ft_putendl_fd("mem alloc failed", 2) : 0;
	err == 11 ? ft_putendl_fd("resolution is missing", 2) : 0;
	err == 12 ? ft_putendl_fd("map params is wrong", 2) : 0;
	err == 13 ? ft_putendl_fd("impossible char in a map", 2) : 0;
	err == 14 ? ft_putendl_fd("can not read map", 2) : 0;
	err == 15 ? ft_putendl_fd("no player on the map", 2) : 0;
	err == 16 ? ft_putendl_fd("wrong map file", 2) : 0;
	err == 17 ? ft_putendl_fd("too big screenshot. max side 16384", 2) : 0;
	err == 18 ? ft_putendl_fd("too low or neg res. min - 32*32", 2) : 0;
	exit(2);
}
