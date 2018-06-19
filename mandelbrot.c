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
	t_mandel man;
	int x1;
	int y1;
	int x2;
	int y2;	
	int max_iter;
	int iteration;
	float c;
	float z;

/**/x1 = 20;
/**/y1 = 20;
	man.lim_x[1] = win->center_x - x1;
	man.lim_y[1] = win->center_y - y1;
	while (x1++ <= man.lim_x[1])
	{
		while (y1++ <= man.lim_y[1])
		{
			iteration = 0;
			c = x1 + y1;
			z = 0;
			while (fabs(z) < man.lim_x[1] && fabs(z) < man.lim_y[1] && iteration <= max_iter)
			{
				z = z * z + c;
				iteration++;
			}
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, 0xff00ff);
		}
	}
}
