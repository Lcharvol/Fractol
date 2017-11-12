/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:29:41 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/28 16:29:42 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_choose_fract(t_env *p)
{
	if (ft_strequ(p->name, "mandelbrot"))
		ft_mandelbrot(p);
	else if (ft_strequ(p->name, "julia"))
		ft_julia(p);
	else
		exit(1);
}

int			main(int argc, char **argv)
{
	t_env	*p;

	if (argc != 2)
		error("Use fractal julia or mandelbrot");
	if (!(ft_strequ(argv[1], "julia") ||
		ft_strequ(argv[1], "mandelbrot") ||
		ft_strequ(argv[1], "newton")))
	{
		error("Wrong fractal, use julia or mandelbrot");
	}
	p = (t_env *)malloc(sizeof(t_env));
	p->name = argv[1];
	ft_init_struct(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Fractol-lcharvol");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
	mlx_key_hook(p->win, ft_key_hook, p);
	mlx_hook(p->win, 6, (1L << 6), ft_move_mouse_hook, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	mlx_loop(p->mlx);
	free(p);
	return (0);
}
