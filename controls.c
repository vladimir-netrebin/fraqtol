/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2020/07/21 14:36:52 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"

static void	draw_help(t_fraqtol *fraq)
{
	mlx_string_put(fraq->mlx, fraq->window, 0, 30, COLOR_S,
		"Controls");
	mlx_string_put(fraq->mlx, fraq->window, 0, 60, COLOR_S,
		"Reset:        R");
	mlx_string_put(fraq->mlx, fraq->window, 0, 90, COLOR_S,
		"Color Shift:  C");
	mlx_string_put(fraq->mlx, fraq->window, 0, 120, COLOR_S,
		"Move:         Arrows");
	mlx_string_put(fraq->mlx, fraq->window, 0, 150, COLOR_S,
		"Zoom:         Scroll");
	mlx_string_put(fraq->mlx, fraq->window, 0, 180, COLOR_S,
		"Detailing:    +/-");
	mlx_string_put(fraq->mlx, fraq->window, 0, 210, COLOR_S,
		"Julia:        Mouse");
	mlx_string_put(fraq->mlx, fraq->window, 0, 240, COLOR_S,
		"Mouse Lock:   Space");
	mlx_string_put(fraq->mlx, fraq->window, 0, 270, COLOR_S,
		"Close Help:   H");
}



static void	help(t_fraqtol *fraq)
{
	fraq->help = !fraq->help;
	if (fraq->help)
		draw_help(fraq);
	else
		draw_fraq(fraq);
}

static void	move(int key, t_fraqtol *fraq)
{
	t_complex d;

	d = init_complex(fabs(fraq->max.re - fraq->min.re),
		fabs(fraq->max.im - fraq->min.im));
	if (key == ARROW_LEFT)
	{
		fraq->min.re -= d.re * 0.05;
		fraq->max.re -= d.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fraq->min.re += d.re * 0.05;
		fraq->max.re += d.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fraq->min.im += d.im * 0.05;
		fraq->max.im += d.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fraq->min.im -= d.im * 0.05;
		fraq->max.im -= d.im * 0.05;
	}
	draw_fraq(fraq);
}

static void	change_max_iter(int key, t_fraqtol *fraq)
{
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
	{
		if (fraq->max_iteration < 50)
			fraq->max_iteration += 1;
		else if (fraq->max_iteration < 1000000000)
			fraq->max_iteration = (int)(fraq->max_iteration * 1.05);
	}
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
	{
		if (fraq->max_iteration > 50)
			fraq->max_iteration = (int)(fraq->max_iteration * 0.95);
		else if (fraq->max_iteration > 1)
			fraq->max_iteration -= 1;
	}
	draw_fraq(fraq);
}

int			key_press(int key, t_fraqtol *fraq)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_H)
		help(fraq);
	else if (!fraq->help)
	{
		if (key == MAIN_PAD_R)
		{
			set_def(fraq);
			draw_fraq(fraq);
		}
		else if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS
				|| key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
			change_max_iter(key, fraq);
		else if (key == ARROW_LEFT || key == ARROW_RIGHT
				|| key == ARROW_UP || key == ARROW_DOWN)
			move(key, fraq);
		else if (key == MAIN_PAD_C)
			change_color_shift(fraq);
		else if (key == MAIN_PAD_SPACE)
			fraq->fix_jul = !fraq->fix_jul;
	}
	return (0);
}
