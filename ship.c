/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 19:05:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"

int		iterate_burning_ship(t_fraqtol *fraq)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(fraq->c.re, fraq->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iter < fraq->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fraq->c.re,
			-2.0 * fabs(z.re * z.im) + fraq->c.im);
		iter++;
	}
	return (iter);
}
