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
		win->thread[i].move_x -= win->thread[i].buf_r;
		win->thread[i].move_y -= win->thread[i].buf_i;
		i++;
	}
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
//		ft_keyhook(KEY_PLUS, win);
		scaling_mouse(x, y, win);
	}
	win->mouse_button.x = x;
	win->mouse_button.y = y;
	return (0);
}

int		mouse_move(int x, int y, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD && (win->fract_id == 1 || win->fract_id == 3) && win->mouse_julia == 1)
	{
		win->thread[i].mouse.x = x;
		win->thread[i].mouse.y = y;
		win->thread[i].buf_r = 1.5 * (win->thread->mouse.x - WIDTH / 2) / (0.5 * win->thread->zoom * WIDTH) + win->thread->move_x;
		win->thread[i].buf_i = (win->thread->mouse.y - HEIGHT / 2) / (0.5 * win->thread->zoom * HEIGHT) + win->thread->move_y;
		// win->thread[i].buf_r = 1.5 * (win->thread->mouse.x - WIDTH / 2) / (0.5 * WIDTH) + win->thread->move_x;
		// win->thread[i].buf_i = (win->thread->mouse.y - HEIGHT / 2) / (0.5 * HEIGHT) + win->thread->move_y;
		i++;
	}
	if (win->fract_id == 1 && win->mouse_julia == 1)
		julia(win);
	else if (win->fract_id == 3 && win->mouse_julia == 1)
		julia_3d(win);
	printf("R::%f\n", win->thread[0].buf_r);
	printf("I::%f\n", win->thread[0].buf_i);
	return (0);
}
