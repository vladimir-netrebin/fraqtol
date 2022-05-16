/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/20 19:05:08 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraq.h"

static int			(*get_law(char *name))(t_fraqtol *fraq)
{
	size_t			i;
	int				(*law)(t_fraqtol *fraq);
	static t_law	laws[] = {
		{"Mandelbrot", &iterate_mandelbrot},
		{"Julia", &iterate_julia},
		{"Burning_ship", &iterate_burning_ship},
		{"Perpendicular_mandelbrot", &iterate_perp_mandelbrot}
	};

	i = 0;
	law = NULL;
	while (i < sizeof(laws) / sizeof(t_law))
	{
		if (ft_strequ(name, laws[i].name))
			law = laws[i].law;
		i++;
	}
	return (law);
}

static t_fraqtol	*init_fraq(char *name, void *mlx)
{
	t_fraqtol *fraq;

	if (!(fraq = (t_fraqtol *)ft_memalloc(sizeof(t_fraqtol))))
		ft_error(ERR_FRAQ);
	fraq->mlx = mlx;
	if (!(fraq->window = mlx_new_window(mlx, WIDTH, HEIGHT, name)))
		ft_error(ERR_WINDOW);
	fraq->image = init_image(mlx);
	set_def(fraq);
	fraq->fix_jul = 1;
	if (!(fraq->law = get_law(name)))
		ft_error(ERR_FRAQ_N);
	fraq->help = 0;
	mlx_hook(fraq->window, 2, 0, key_press, fraq);
	mlx_hook(fraq->window, 17, 0, f_close, fraq);
	mlx_hook(fraq->window, 4, 0, zoom, fraq);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fraq->window, 6, 0, julia_mot, fraq);
	return (fraq);
}

static void			go(int num, char **nam)
{
	t_fraqtol	*fraq[2];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < num)
	{
		fraq[i] = init_fraq(nam[i], mlx);
		draw_fraq(fraq[i]);
		i++;
	}
	mlx_loop(mlx);
}

int					main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2 && ac <= 11)
	{
		while (i < ac)
		{
			if (!get_law(av[i]))
				break ;
			i++;
		}
		if (i == ac)
			go(ac - 1, &av[1]);
	}
	message();
	return (0);
}
