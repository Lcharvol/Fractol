/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:07:10 by lcharvol          #+#    #+#             */
/*   Updated: 2017/06/18 14:36:18 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		mandelbrot__(t_env *p, int x, int y)
{
	p->c_r = x / p->zoom_x + p->x1;
	p->c_i = y / p->zoom_y + p->y1;
	p->z_r = 0;
	p->z_i = 0;
	p->i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && p->i < p->iteration_max)
	{
		p->tmp = p->z_r - (p->var / 5000);
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * p->tmp + p->c_i;
		p->i = p->i + 1;
	}
	if (p->i == p->iteration_max)
	{
		p->r = 255;
		p->v = 255;
		p->b = 255;
	}
	else
	{
		p->r = (p->i * p->color1) / (p->iteration_max);
		p->v = (p->i * p->color2) / (p->iteration_max);
		p->b = (p->i * p->color3) / (p->iteration_max);
	}
	draw(p, x, y);
}

void		mandelbrot(t_env *p)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot__(p, x, y);
			y++;
		}
		x++;
	}
}
