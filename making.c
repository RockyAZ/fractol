/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:13:01 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/06 16:13:02 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_zoom(t_win *win)
{
	int		i;
	double	cp;

	i = 0;
    //0.3
	cp = 0.5;
	while (i < ZOOM)
	{
		win->zooms[i] = cp;
		cp *= 1.1;
		i++;
	}
}

void	make_win(t_win *win)
{
	win->mouse_down = 0;
	win->is_text = 1;
	win->mouse_julia = 1;
	win->zoom_id = 0;
	win->move_size = 0.2;
}

int		make_threads_color(int i)
{
	if (i >= COLORS)
	{
		while (i >= COLORS && i > 0)
			i -= COLORS;
		if (i >= 0)
			return (i);
		else
		{
			while (i < 0)
				i++;
			return (i);
		}
	}
	return (i);
}

void	make_thread(t_win *win)
{
	int i;
	int dive;

	i = 0;
	dive = HEIGHT / THREAD;
	while (i < THREAD)
	{
		win->thread[i].y = i * dive;
		win->thread[i].lim_y = win->thread[i].y + dive;
		win->thread[i].iter = 80;
        //0.3
		win->thread[i].zoom = 0.5;
		win->thread[i].move_x = 0;
		win->thread[i].move_y = 0;
		win->thread[i].mouse.x = WIDTH / 2;
		win->thread[i].mouse.y = HEIGHT / 2;
		win->thread[i].dive = dive;
		if (win->thr_color == 1 && (win->fract_id == 1 || win->fract_id == 3))
			win->thread[i].color_id = make_threads_color(i);
		else if (win->thr_color == -1)
			win->thread[i].color_id = 5;
		i++;
	}
	make_win(win);
}

double	make_complex(int x, int y, t_win *win, char c)
{
	if (c == 'r')
		return (1.5 * (x - WIDTH / 2) / (win->thread->zoom * WIDTH));
	if (c == 'i')
			return ((y - HEIGHT / 2) / (win->thread->zoom * HEIGHT));
	return (-1);
}