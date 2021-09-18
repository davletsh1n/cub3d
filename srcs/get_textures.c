/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:52:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/02/23 14:52:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_sprite(t_all *all, char *line, t_vars *v)
{
	char *trim;

	trim = ft_strtrim(line, " ");
	all->tex->sprt->img = mlx_xpm_file_to_image(all->win->mlx,
		trim, &all->tex->sprt->wi, &all->tex->sprt->he);
	!all->tex->sprt->img ? parse_errno(6) : 0;
	all->tex->sprt->addr = mlx_get_data_addr(all->tex->sprt->img,
		&all->tex->sprt->bpp, &all->tex->sprt->line_l, &all->tex->sprt->en);
	!all->tex->sprt->addr ? parse_errno(6) : 0;
	free(trim);
	v->sp = 1;
}

void	get_east(t_all *all, char *line, t_vars *v)
{
	char *trim;

	trim = ft_strtrim(line, " ");
	all->tex->ea->img = mlx_xpm_file_to_image(all->win->mlx,
		trim, &all->tex->ea->wi, &all->tex->ea->he);
	!all->tex->ea->img ? parse_errno(6) : 0;
	all->tex->ea->addr = mlx_get_data_addr(all->tex->ea->img,
		&all->tex->ea->bpp, &all->tex->ea->line_l, &all->tex->ea->en);
	!all->tex->ea->addr ? parse_errno(6) : 0;
	free(trim);
	v->ea = 1;
}

void	get_west(t_all *all, char *line, t_vars *v)
{
	char *trim;

	trim = ft_strtrim(line, " ");
	all->tex->we->img = mlx_xpm_file_to_image(all->win->mlx,
		trim, &all->tex->we->wi, &all->tex->we->he);
	!all->tex->we->img ? parse_errno(6) : 0;
	all->tex->we->addr = mlx_get_data_addr(all->tex->we->img,
		&all->tex->we->bpp, &all->tex->we->line_l, &all->tex->we->en);
	!all->tex->we->addr ? parse_errno(6) : 0;
	free(trim);
	v->we = 1;
}

void	get_south(t_all *all, char *line, t_vars *v)
{
	char *trim;

	trim = ft_strtrim(line, " ");
	all->tex->so->img = mlx_xpm_file_to_image(all->win->mlx,
		trim, &all->tex->so->wi, &all->tex->so->he);
	!all->tex->so->img ? parse_errno(6) : 0;
	all->tex->so->addr = mlx_get_data_addr(all->tex->so->img,
		&all->tex->so->bpp, &all->tex->so->line_l, &all->tex->so->en);
	!all->tex->so->addr ? parse_errno(6) : 0;
	free(trim);
	v->so = 1;
}

void	get_north(t_all *all, char *line, t_vars *v)
{
	char *trim;

	trim = ft_strtrim(line, " ");
	all->tex->no->img = mlx_xpm_file_to_image(all->win->mlx,
		trim, &all->tex->no->wi, &all->tex->no->he);
	!all->tex->no->img ? parse_errno(6) : 0;
	all->tex->no->addr = mlx_get_data_addr(all->tex->no->img,
		&all->tex->no->bpp, &all->tex->no->line_l, &all->tex->no->en);
	!all->tex->no->addr ? parse_errno(6) : 0;
	free(trim);
	v->no = 1;
}
