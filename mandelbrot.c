/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:21:48 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 17:21:48 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_win *win)
{
	t_mandel	man;
	int			x;
	int			y;
	int			i;

	y = 0;
	prepare(win);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			man.buf_r = 1.5 * (x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
			man.buf_i = (y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
			man.rn[1] = 0;
			man.in[1] = 0;
			i = 0;
			while (i < win->iter)
			{
				man.rn[0] = man.rn[1];
				man.in[0] = man.in[1];
				man.rn[1] = man.rn[0] * man.rn[0] - man.in[0] * man.in[0] + man.buf_r;
				man.in[1] = 2 * man.rn[0] * man.in[0] + man.buf_i;
				if ((man.rn[1] * man.rn[1] + man.in[1] * man.in[1]) > 4)
					break ;
				i++;
			}
			set_pixel(x, y, i, win);
			x++;
		}
		y++;
	}
	drawing(win);
}
