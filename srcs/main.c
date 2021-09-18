/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:26:00 by ssandman          #+#    #+#             */
/*   Updated: 2021/03/04 14:26:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		closing(t_all *all)
{
	if (all)
		exit(0);
	return (0);
}

void	create_screen(unsigned char *i, unsigned char *f, t_all *all)
{
	int		fd;
	int		size;
	int		line;

	line = 0;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0777)) < 0)
		parse_errno(14);
	write(fd, f, 14);
	write(fd, i, 40);
	size = all->wres * all->win->bpp / 8;
	while (line < all->hres)
	{
		write(fd, all->win->addr + line * all->win->line_l, size);
		line++;
	}
	close(fd);
}

void	put_bmpheader(unsigned char *i, unsigned char *f, t_all *all)
{
	int size;

	size = 14 + 40 + all->wres * all->hres * all->win->bpp / 8;
	i[0] = 40;
	i[4] = all->wres;
	i[5] = all->wres >> 8;
	i[6] = all->wres >> 16;
	i[7] = all->wres >> 24;
	i[8] = -all->hres;
	i[9] = -all->hres >> 8;
	i[10] = -all->hres >> 16;
	i[11] = -all->hres >> 24;
	i[12] = 1;
	i[14] = all->win->bpp;
	f[0] = 'B';
	f[1] = 'M';
	f[2] = size;
	f[3] = size >> 8;
	f[4] = size >> 16;
	f[5] = size >> 24;
	f[10] = 54;
}

int		screenshot(t_all *all)
{
	unsigned char file_data[14];
	unsigned char info_data[40];

	ft_bzero(file_data, 14);
	ft_bzero(info_data, 40);
	raycast(all);
	put_bmpheader(info_data, file_data, all);
	create_screen(info_data, file_data, all);
	ft_putstr_fd("done! ./screenshot.bmp saved\n", 1);
	exit(0);
}

int		main(int ac, char **av)
{
	t_win	win;
	t_ray	ray;
	t_all	all;
	t_tex	textures;

	all.win = &win;
	all.ray = &ray;
	init_rays(&all);
	check_args(ac, av, &all);
	all.tex = &textures;
	init_textures(&all);
	win.mlx = mlx_init();
	parse_file(av, &all);
	win.img = mlx_new_image(win.mlx, all.wres, all.hres);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	all.shoot == 1 ? screenshot(&all) : 0;
	win.win = mlx_new_window(win.mlx, all.wres, all.hres, "cub3D");
	mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
	mlx_hook(win.win, 33, 1L << 0, &closing, &all);
	mlx_hook(win.win, 2, 1L << 0, deal_key, &all);
	raycast(&all);
	mlx_loop(win.mlx);
}
