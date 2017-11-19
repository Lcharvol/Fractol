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

void		zoomIn(int x, int y, t_env *p)
{
	p->zoom *= 1.1;

	p->x1 += (0.1 - (p->zoom / 100000)) * ((x / (double)(WIDTH / 2)) - 1);
	p->y1 += (0.1 - (p->zoom / 100000)) * ((y / (double)(HEIGHT / 2)) - 1);
}

void		zoomOut(int x, int y, t_env *p)
{
	p->zoom *= 0.9;

	p->x1 += (0.1) * ((x / (double)(WIDTH / 2)) - 1);
	p->y1 += (0.1) * ((y / (double)(HEIGHT / 2)) - 1);
}
