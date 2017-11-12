/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:30:45 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/28 16:30:47 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define WIDTH 800
# define HEIGHT 800
# define ECHAP	53
# define UP		126
# define DOWN	125
# define RIGHT	124
# define LEFT	123
# define ZOOM	69
# define DEZOOM	78

typedef struct		s_env
{
	int 			color1;
	int 			color2;
	int 			color3;
	double 			c_r;
	double 			c_i;
	double 			z_r;
	double 			z_i;
	double 			i;
	double 			tmp;
	int 			space;
	double			var;
	double 			zoom_x;
	double 			zoom_y;
	double 			x1;
	double 			x2;
 	double 			y1;
	double 			y2;
	char 			*name;
	double 			r;
	double 			v;
	double 			b;
	double			zoom;
	double			iteration_max;
	int				x;
	int				y;
	char			*ret;
	void			*win;
	void			*mlx;
	void			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_env;

void				ft_choose_fract(t_env *p);
void				ft_print_info(t_env *p);
static int			ft_loop_key_hook(t_env *p);
int					ft_key_hook(int keycode, t_env *p);
int					ft_move_mouse_hook(int x, int y, t_env *p);
int					ft_mouse_hook(int button, int x, int y, t_env *p);
void				ft_init_struct(t_env *p);
void				ft_draw(t_env *p, int x, int y);
void				ft_julia(t_env *p);
void				ft_mandelbrot(t_env *p);
void				error(char *str);
#endif
