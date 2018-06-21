/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:39:19 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 13:39:20 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	julia(t_win *win)
{write(1, "j\n", 2);
	t_mandel	man;
	int			x;
	int			y;
	int			i;

	man.lim = ft_min(WIDTH, HEIGHT);
	y = 0;
	prepare(win);
	man.buf_r = 1.5 * (win->mouse.x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
	man.buf_i = (win->mouse.y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			man.rn[1] = 1.5 * (x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
			man.in[1] = (y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
			i = 0;
			while (i < win->iter)
			{
				man.rn[0] = man.rn[1];
				man.in[0] = man.in[1];
				man.rn[1] = ((man.rn[0] * man.rn[0]) - (man.in[0] * man.in[0])) + man.buf_r;
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
