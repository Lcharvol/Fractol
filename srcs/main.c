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

void		chooseFractol(t_env *p)
{
	if (ft_strequ(p->name, "mandelbrot"))
		mandelbrot(p);
	else if (ft_strequ(p->name, "julia"))
		julia(p);
	else
		exit(1);
}

void		displayErrors(int argc, char **argv)
{
	if (argc != 2)
		error("Use fractal julia or mandelbrot");
	if (!(ft_strequ(argv[1], "julia") ||
		ft_strequ(argv[1], "mandelbrot") ||
		ft_strequ(argv[1], "newton")))
	{
		error("Wrong fractal: Use julia or mandelbrot");
	}
}

int			main(int argc, char **argv)
{
	t_env	*p;

	displayErrors(argc, argv);
	p = (t_env *)malloc(sizeof(t_env));
	p->name = argv[1];
	initStructure(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Fractol-lcharvol");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
	mlx_key_hook(p->win, keyHook, p);
	mlx_hook(p->win, 6, (1L << 6), moveMouseHook, p);
	mlx_mouse_hook(p->win, mouseHook, p);
	mlx_loop(p->mlx);
	free(p);
	return (0);
}
