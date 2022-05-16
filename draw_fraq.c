/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fraq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 19:05:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"
#include <pthread.h>

static void	put_pixel(t_fraqtol *fraq, int x, int y, t_color color)
{
	int	i;

	i = (x * fraq->image->b_p_p / 8) + (y * fraq->image->size);
	fraq->image->d_addr[i] = color.chanel[3];
	fraq->image->d_addr[++i] = color.chanel[2];
	fraq->image->d_addr[++i] = color.chanel[1];
	fraq->image->d_addr[++i] = color.chanel[0];
}

static void	draw_fraq_p(t_fraqtol *fraq)
{
	int		y;
	int		x;
	t_color	color;

	y = fraq->start;
	while (y < fraq->finish)
	{
		fraq->c.im = fraq->max.im - y * fraq->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fraq->c.re = x * fraq->factor.re + fraq->min.re;
			color = get_color(fraq->law(fraq), fraq);
			put_pixel(fraq, x, y, color);
			x++;
		}
		y++;
	}
}

void		draw_fraq(t_fraqtol *fraq)
{
	pthread_t	tred[NUM];
	t_fraqtol	fraqs[NUM];
	int			i;

	i = 0;
	fraq->factor = init_complex(
		(fraq->max.re - fraq->min.re) / (WIDTH - 1),
		(fraq->max.im - fraq->min.im) / (HEIGHT - 1));
	while (i < NUM)
	{
		fraqs[i] = *fraq;
		fraqs[i].start = i * (HEIGHT / NUM);
		fraqs[i].finish = (i + 1) * (HEIGHT / NUM);
		if (pthread_create(&tred[i], NULL,
			(void *(*)(void *))draw_fraq_p, (void *)&fraqs[i]))
			ft_error(ERR_TR);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(tred[i], NULL))
			ft_error(ERR_TR);
	mlx_put_image_to_window(fraq->mlx,
		fraq->window, fraq->image->image, 0, 0);
	mlx_string_put(fraq->mlx, fraq->window, 0, 0, COLOR_S, "H - for help");
}
