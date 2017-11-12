/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:12:15 by lcharvol          #+#    #+#             */
/*   Updated: 2017/06/18 14:52:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	loopKeyHook(t_env *p)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	x = 0;
	chooseFractol(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	// ft_print_info(p);
	return (0);
}

int			keyHook__(int keycode, t_env *p)
{
	if (keycode == RIGHT)
	{
		p->x1 -= 0.1;
		p->x2 -= 0.1;
	}
	if (keycode == LEFT)
	{
		p->x1 += 0.1;
		p->x2 += 0.1;
	}
	if (keycode == ZOOM)
		p->iteration_max += 10;
	if (keycode == DEZOOM)
		p->iteration_max -= 10;
	if (keycode == 18)
		p->color1 += 50;
	if (keycode == 19)
		p->color2 += 50;
	if (keycode == 20)
		p->color2 += 50;
	loopKeyHook(p);
	return (0);
}

int			keyHook(int keycode, t_env *p)
{
	int		i;
	int		j;

	i = 1;
	if (keycode == 49)
	{
		if (p->space == 1)
			p->space = 0;
		else
			p->space = 1;
	}
	if (keycode == 117)
		initStructure(p);
	if (keycode == ECHAP)
		exit(1);
	if (keycode == UP)
		p->y1 *= 1.1;
	if (keycode == DOWN)
		p->y1 *= 0.9;
	return (keyHook__(keycode, p));
}

int			moveMouseHook(int x, int y, t_env *p)
{
	if (p->space == 1)
	{
		p->var = (x * y) / 100;
		loopKeyHook(p);
	}
	return (0);
}

void		zoomIn(int x, int y, t_env *p)
{
	p->zoom *= 1.1;

	ft_putnbr(p->zoom);
	ft_putchar('\n');
	p->x1 += (0.1 - (p->zoom / 100000)) * ((x / (double)(WIDTH / 2)) - 1);
	p->y1 += (0.1 - (p->zoom / 100000)) * ((y / (double)(HEIGHT / 2)) - 1);
}

void		zoomOut(int x, int y, t_env *p)
{
	p->zoom *= 0.9;

	p->x1 += (0.1) * ((x / (double)(WIDTH / 2)) - 1);
	p->y1 += (0.1) * ((y / (double)(HEIGHT / 2)) - 1);
}

int			mouseHook(int button, int x, int y, t_env *p)
{
	ft_putnbr(button);
	if (button == SCROLL_IN || button == LEFT_CLIC)
		zoomIn(x, y, p);
	if (button == SCROLL_OUT || button == RIGHT_CLIC)
		zoomOut(x, y, p);
	loopKeyHook(p);
	return (0);
}
