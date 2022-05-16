/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraq.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:23:15 by ivalenti          #+#    #+#             */
/*   Updated: 2020/07/21 14:37:13 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAQ_H

# define FRAQ_H

# define NUM		10

# define WIDTH		1000
# define HEIGHT		1000

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49
# define MAIN_PAD_C			8
# define MAIN_PAD_H			4
# define MAIN_PAD_R			15
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27

# define COLOR_S			0xCCCCCC
# define COLOR_T			0x444444

# define ERR_FRAQ	"ERROR: Can\'t initialize fractol"
# define ERR_WINDOW	"ERROR: Can\'t initialize window"
# define ERR_IMAGE	"ERROR: Can\'t initialize image"
# define ERR_FRAQ_N	"ERROR: No such fractal"
# define ERR_TR		"ERROR: There is a problem with threads"

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef	struct	s_color
{
	int			chanel[4];
}				t_color;



typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef	struct	s_image
{
	void		*image;
	char		*d_addr;
	int			b_p_p;
	int			size;
	int			end;
}				t_image;

typedef struct	s_fraqtol
{
	void		*mlx;
	void		*window;
	t_image		*image;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			fix_jul;
	int			start;
	int			finish;
	int			color_sh;
	int			(*law)(struct s_fraqtol *fraq);
	int			help;
}				t_fraqtol;

typedef	struct	s_law
{
	char		*name;
	int			(*law)(t_fraqtol *fraq);
}				t_law;

t_complex		init_complex(double re, double im);

int				iterate_mandelbrot(t_fraqtol *fractol);

int				iterate_julia(t_fraqtol *fractol);

int				iterate_burning_ship(t_fraqtol *fraq);

int				iterate_perp_mandelbrot(t_fraqtol *fraq);

t_image			*init_image(void *mlx);

void			set_def(t_fraqtol *fractol);

t_color			get_color(int iter, t_fraqtol *fraq);

void			ft_error(char *s);

void			draw_fraq(t_fraqtol *fraq);

int				zoom(int but, int x, int y, t_fraqtol *fraq);

int				key_press(int key, t_fraqtol *fraq);

int				julia_mot(int x, int y, t_fraqtol *fraq);

void			message(void);

void			change_color_shift(t_fraqtol *fraq);

int				f_close(void);

#endif
