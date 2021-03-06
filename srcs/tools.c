/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:08:24 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/03 21:08:26 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void		printInfo(t_env *p)
{
	char	*str;

	str = "Iterations: ";
	mlx_string_put(p->mlx, p->win, 10, 10, 0x0FFFFFF, str);
	str = ft_itoa(p->iteration_max);
	mlx_string_put(p->mlx, p->win, 130, 10, 0x0FFFFFF, str);
}

void		draw(t_env *p, int x, int y)
{
	p->ret[(x * 4 + (y * WIDTH * 4))] = p->b;
	p->ret[(x * 4 + (y * WIDTH * 4)) + 1] = p->v;
	p->ret[(x * 4 + (y * WIDTH * 4)) + 2] = p->r;
	p->ret[(x * 4 + (y * WIDTH * 4)) + 3] = 0;
}

void		initStructure__(t_env *p)
{
	if (ft_strequ(p->name, "mandelbrot"))
	{
		p->zoom = 100;
		p->x1 = -2.1;
		p->x2 = 0.6;
		p->y1 = -1.2;
		p->y2 = 1.2;
	}
	else if (ft_strequ(p->name, "julia"))
	{
		p->zoom = 350;
		p->x1 = -1;
		p->x2 = 1;
		p->y1 = -1.2;
		p->y2 = 1.2;
	}
	else if (ft_strequ(p->name, "burningship"))
	{
		p->zoom = 350;
		p->x1 = -1;
		p->x2 = 1;
		p->y1 = -1.2;
		p->y2 = 1.2;
	}
}

void		initStructure(t_env *p)
{
	p->color1 = 150;
	p->color2 = 200;
	p->color3 = 255;
	p->space = 0;
	p->var = 0;
	p->r = 0;
	p->v = 0;
	p->b = 0;
	p->iteration_max = 50;
	p->zoom_x = WIDTH / (p->x2 - p->x1) + p->zoom;
	p->zoom_y = HEIGHT / (p->y2 - p->y1) + p->zoom;
	initStructure__(p);
}
