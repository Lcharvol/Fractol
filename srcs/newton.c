/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 00:26:47 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/04 00:26:49 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calculate(t_env *p, double x0, double y0)
{
	double	xx;
	double	yy;
	double	i2;

	i2 = 0;
	while (++(p->i) < p->iteration_maxr)
	{
		xx = 2 * x0 / 3 - (x0 * x0 - y0 * y0) / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		yy = 2 * y0 / 3 + 2 * x0 * y0 / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		x0 = xx;
		y0 = yy;
		if (p->i == p->iteration_max)
		{
			p->r = 255;
			p->v = 255;
			p->b = 255;
			draw(p, x, y);
		}
		else
		{
			p->r = (p->i * p->color1) / (p->iteration_max);
			p->v = (p->i * p->color2) / (p->iteration_max);
			p->b = (p->i * p->color3) / (p->iteration_max);
			draw(p, x, y);
		}
	}

}

void	newton(t_env *p)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate(p, x, y);
			x++;
		}
		y++;
	}
}