/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 19:05:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"

static double	demi(double start, double end, double gap)
{
	return (start + ((end - start) * gap));
}

int				zoom(int but, int x, int y, t_fraqtol *fraq)
{
	t_complex	mouse;
	double		inter;
	double		zoom;

	if (!fraq->help &&
		(but == MOUSE_SCROLL_UP || but == MOUSE_SCROLL_DOWN))
	{
		mouse = init_complex(
			(double)x / (WIDTH / (fraq->max.re - fraq->min.re))
				+ fraq->min.re,
			(double)y / (HEIGHT / (fraq->max.im - fraq->min.im))
				* -1 + fraq->max.im);
		if (but == MOUSE_SCROLL_UP)
			zoom = 0.50;
		else
			zoom = 2.0;
		inter = 1 / zoom;
		fraq->min.re = demi(mouse.re, fraq->min.re, inter);
		fraq->min.im = demi(mouse.im, fraq->min.im, inter);
		fraq->max.re = demi(mouse.re, fraq->max.re, inter);
		fraq->max.im = demi(mouse.im, fraq->max.im, inter);
		draw_fraq(fraq);
	}
	return (0);
}

int				julia_mot(int x, int y, t_fraqtol *fraq)
{
	if (!fraq->help && !fraq->fix_jul)
	{
		fraq->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fraq(fraq);
	}
	return (0);
}
