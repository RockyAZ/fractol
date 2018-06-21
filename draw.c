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

void	prepare(t_win *win)
{
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
}

void	set_pixel(int x, int y, int i, t_win *win)
{
	int p;

	p = (x * 4) + (y * win->size_line);
	win->ptr[p] = i % 256 * (i < win->iter);
	win->ptr[++p] = 255 * (i < win->iter);
	win->ptr[++p] = 255 * (i < win->iter);
}

void	drawing(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
