/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:52:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/15 14:52:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wrong_args(int err)
{
	ft_putendl_fd("Error", 2);
	err == 1 ? ft_putendl_fd("no map", 2) : 0;
	err == 2 ? ft_putendl_fd("too many arguments", 2) : 0;
	err == 3 ? ft_putendl_fd("map is not in *.cub format", 2) : 0;
	err == 4 ? ft_putendl_fd("wrong second argument, try --save", 2) : 0;
	exit(2);
}

int		check_ext(char *arg)
{
	size_t	len;

	len = ft_strlen(arg) - 4;
	if (ft_strncmp(&arg[len], ".cub", 4))
		return (1);
	return (0);
}

int		check_save(char *arg, t_all *all)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((!(ft_strncmp(arg, "--save", 7)) && len == 6))
	{
		all->shoot = 1;
		return (1);
	}
	return (0);
}

int		check_args(int ac, char **av, t_all *all)
{
	ac == 1 ? wrong_args(1) : 0;
	ac > 3 ? wrong_args(2) : 0;
	(check_ext(av[1])) ? wrong_args(3) : 0;
	if (ac == 3)
		check_save(av[2], all) ? 0 : wrong_args(4);
	return (0);
}
