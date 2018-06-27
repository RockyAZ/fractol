/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:47:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 15:47:13 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prepare_draw(t_win *win)
{
	int i;

	i = 0;
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->img.ptr = (unsigned char*)mlx_get_data_addr(win->img.img_ptr,
	&win->img.bpp, &win->img.size_line, &win->img.endian);
	while (i < THREAD)
	{
		win->thread[i].size_line = win->img.size_line;
		win->thread[i].img_ptr = win->img.ptr;
		i++;
	}
}

void	set_pixel(int x, int y, int i, t_thread *thr)
{
	int p;

	p = (x * 4) + (y * thr->size_line);
	if (thr->move_x == 0)
	{
	thr->img_ptr[p] = 255;
	thr->img_ptr[++p] = 255;
	thr->img_ptr[++p] = 255;
	}
	else
	{		
	thr->img_ptr[p] = (255 - i) * (i < thr->iter);
	thr->img_ptr[++p] = i % 255 * (i < thr->iter);
	thr->img_ptr[++p] = i % 255 * (i < thr->iter);
	}
}

void	drawing(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
}
