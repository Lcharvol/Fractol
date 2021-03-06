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
# define PLUS	78
# define LESS	69
# define RIGHT_CLIC 2
# define LEFT_CLIC 1
# define SCROLL_IN 5
# define SCROLL_OUT 4
# define DELETE 117
# define SPACE_BAR 49
# define NUMBER_ONE 18
# define NUMBER_TWO 19
# define NUMBER_THREE 20

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

void				chooseFractol(t_env *p);
void				printInfo(t_env *p);
static int			loopKeyHook(t_env *p);
int					keyHook(int keycode, t_env *p);
int					moveMouseHook(int x, int y, t_env *p);
int					mouseHook(int button, int x, int y, t_env *p);
void				initStructure(t_env *p);
void				draw(t_env *p, int x, int y);
void				julia(t_env *p);
void				mandelbrot(t_env *p);
void				burning_ship(t_env *p);
void				error(char *str);
void				zoomIn(int x, int y, t_env *p);
void				zoomOut(int x, int y, t_env *p);

#endif
