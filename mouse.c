/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:44:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 16:44:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scaling_mouse(int x, int y, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD)
	{
		win->thread[i].zoom = win->zooms[win->zoom_id + 1];
		i++;
	}
	win->zoom_id++;
	win->move_size /= 1.1109;

}

int		mouse_down(int button, int x, int y, t_win *win)
{
	win->mouse_button.x = x;
	win->mouse_button.y = y;
	if (button == MOUSE_MAIN)
		win->mouse_down = 1;
	return (0);
}

int		mouse_up(int button, int x, int y, t_win *win)
{
	(void)button;
	win->mouse_down = 0;
	if (x == win->mouse_button.x && y == win->mouse_button.y)
	{
		scaling_mouse(x, y, win);
	}
	win->mouse_button.x = x;
	win->mouse_button.y = y;
	return (0);
}

int		mouse_move(int x, int y, t_win *win)
{
	int i;
	int x1;
	int y1;

	i = 0;
	x1 = win->thread[0].mouse.x;
	y1 = win->thread[0].mouse.y;
	if (win->mouse_down == 1)
	{
		while (i < THREAD)
		{
			if (x1 < x || x1 > x)
				win->thread[i].move_x += make_complex(x1, 0, win, 'r') - make_complex(x, 0, win, 'r');
			else if (y1 < y)
				win->thread[i].move_y += make_complex(y1, 0, win, 'i') - make_complex(y, 0, win, 'i');
			else if (y1 > y)
				win->thread[i].move_y += make_complex(y1, 0, win, 'i') - make_complex(y, 0, win, 'i');
			i++;
		}
	}
	i = 0;
	while (i < THREAD)
	{
		if ((win->fract_id == 1 || win->fract_id == 3) && win->mouse_julia == 1 && win->mouse_down == 0)
		{
			win->thread[i].buf_r = make_complex(win->thread[i].mouse.x, 0, win, 'r');
			win->thread[i].buf_i = make_complex(0, win->thread[i].mouse.y, win, 'i');
		}
		win->thread[i].mouse.x = x;
		win->thread[i].mouse.y = y;
		i++;
	}
	if (win->fract_id == 1 && win->mouse_julia == 1)
		julia(win);
	else if (win->fract_id == 3 && win->mouse_julia == 1)
		julia_3d(win);
	return (0);
}
