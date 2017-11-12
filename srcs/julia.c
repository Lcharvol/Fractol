/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:06:55 by lcharvol          #+#    #+#             */
/*   Updated: 2017/06/18 14:06:52 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		julia__(t_env *p, int x, int y)
{
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->z_r = x / p->zoom + p->x1;
	p->z_i = y / p->zoom + p->y1;
	p->i = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && p->i < p->iteration_max)
	{
		p->tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r - (p->var / 1000);
		p->z_i = 2 * p->z_i * p->tmp + p->c_i - (p->var / 1000);
		p->i = p->i + 1;
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
}

void		julia(t_env *p)
{
	int		x;
	int		y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			julia__(p, x, y);
			y++;
		}
		x++;
	}
}
