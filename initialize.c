/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 19:05:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"

t_image		*init_image(void *mlx)
{
	t_image *image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		ft_error(ERR_IMAGE);
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		ft_error(ERR_IMAGE);
	image->d_addr = mlx_get_data_addr(image->image,
	&(image->b_p_p),
	&(image->size),
	&(image->end));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		set_def(t_fraqtol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_sh = 0;
}

t_color		get_color(int iter, t_fraqtol *fraq)
{
	t_color	color;
	double	t;

	t = (double)iter / (double)fraq->max_iteration;
	color.chanel[0] = 0;
	color.chanel[(0 + fraq->color_sh) % 3 + 1] =
		(int)(9 * (1 - t) * pow(t, 3) * 255);
	color.chanel[(1 + fraq->color_sh) % 3 + 1] =
		(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.chanel[(2 + fraq->color_sh) % 3 + 1] =
		(int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void		change_color_shift(t_fraqtol *fraq)
{
	fraq->color_sh = (fraq->color_sh + 1) % 3;
	draw_fraq(fraq);
}
