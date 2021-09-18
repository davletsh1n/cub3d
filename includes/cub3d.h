/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 12:21:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/12/24 12:21:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 128
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UARR 65362
# define DARR 65364
# define LARR 65361
# define RARR 65363

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_ray
{
	double		pposx;
	double		pposy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	int			hit;
	double		rotspd;
	double		mvspd;
	double		sdistx;
	double		sdisty;
	double		ddistx;
	double		ddisty;
	double		perpwall;
	int			stepx;
	int			stepy;
	int			hside;
	int			drwheight;
	int			drwstart;
	int			drwstop;
	double		wallx;
	int			texx;
	int			texy;
	int			rgb;
	double		step;
	double		texpos;
	double		sprtx;
	double		sprty;
	double		invdet;
	double		trnx;
	double		trny;
	int			sscrx;
	double		spr_he;
	int			drwstrt_y;
	int			drwend_y;
	double		spr_wi;
	int			drwstrt_x;
	int			drwend_x;
}				t_ray;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			wi;
	int			he;
}				t_img;

typedef struct	s_tex
{
	t_img		*we;
	t_img		*ea;
	t_img		*no;
	t_img		*so;
	t_img		*sprt;
}				t_tex;

typedef struct	s_sprpos
{
	double		x;
	double		y;
	double		d;
}				t_sprpos;

typedef struct	s_all
{
	int			shoot;
	int			wres;
	int			hres;
	int			spnum;
	t_sprpos	*sprites;
	t_win		*win;
	t_ray		*ray;
	char		**map;
	char		**map2;
	t_tex		*tex;
	double		*zb;
	int			wline;
	int			fr;
	int			fg;
	int			fb;
	int			ceiling;
	int			floor;
	int			maplen;
	int			maplon;
	double		asp;
}				t_all;

typedef struct	s_vars
{
	int			re;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			sp;
	int			fl;
	int			ce;
	int			map;
	int			plr;
}				t_vars;

void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
int				raycast(t_all *all);
void			dda_stepinit(t_all *all);
void			dda_init(t_all *all, int x);
void			dda_loop(t_all *all);
void			draw_prep(t_all *all);
void			sides_prep(t_all *all);
void			prep_north(t_all *all);
void			prep_west(t_all *all);
void			prep_east(t_all *all);
void			prep_south(t_all *all);
void			draw_wall(t_all *all, int x);
void			draw_ceiling(t_all *all, int x);
void			draw_floor(t_all *all, int x);
void			draw_north(t_all *all, int x);
void			draw_west(t_all *all, int x);
void			draw_east(t_all *all, int x);
void			draw_south(t_all *all, int x);
void			move_forward(t_all *all);
void			move_back(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);
void			look_left(t_all *all);
void			look_right(t_all *all);
void			wrong_args(int err);
int				check_ext(char *arg);
int				check_save(char *arg, t_all *all);
int				check_args(int ac, char **av, t_all *all);
void			get_east(t_all *all, char *line, t_vars *v);
void			get_west(t_all *all, char *line, t_vars *v);
void			get_north(t_all *all, char *line, t_vars *v);
void			get_south(t_all *all, char *line, t_vars *v);
void			get_sprite(t_all *all, char *line, t_vars *v);
void			parse_errno(int err);
int				numlen(int num);
int				count_spaces(const char *line);
void			init_vars(t_vars *vars);
int				ascii_numlen(char *line);
void			get_ceiling(t_all *all, char *line, t_vars *v);
void			get_floor(t_all *all, char *line, t_vars *v);
void			get_res(t_all *all, t_list *head, t_vars *v);
void			put_player(t_all *all, t_vars *v, int i, int j);
void			sort_sprites(t_all *all);
void			sprite_dist(t_all *all);
int				deal_key(int key, t_all *all);
void			init_rays(t_all *all);
void			init_textures(t_all *all);
void			parse_file(char **av, t_all *all);
void			check_id(t_all *all, t_list *head, t_vars *v);
int				check_params(t_vars *v);
void			mapper(t_all *all, t_list *head, t_vars *v);
int				flood_fill(t_all *all, int i, int j);
void			map_process(t_all *all, t_vars *v);
void			get_sprites(t_all *all);
void			map_valid(t_all *all);
void			map_copy(t_all *all, int max);
void			spriter(t_all *all);
void			draw_sprite(t_all *all, int stripe);
void			calc_sprite(t_all *all, int i);
void			clearlist(t_list *oldhead);
void			parsestart(t_all *all, t_vars *v, int fd, t_list *head);
void			get_wi(int i, t_list *head, t_all *all);
void			get_hi(int i, t_list *head, t_all *all);
void			aspect_fix(t_all *all);
void			get_garbage(char *line, int i);
#endif
