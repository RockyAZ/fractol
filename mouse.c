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

int			mouse_move(int x, int y, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD)
	{
		win->thread[i].mouse.x = x;
		win->thread[i].mouse.y = y;
		win->thread[i].buf_r = 1.5 * (win->thread->mouse.x - WIDTH / 2) / (0.5 * win->thread->zoom * WIDTH) + win->thread->move_x;
		win->thread[i].buf_i = (win->thread->mouse.y - HEIGHT / 2) / (0.5 * win->thread->zoom * HEIGHT) + win->thread->move_y;
		i++;
	}
	if (win->fract_id == 1)
		julia(win);
	return (0);
}
