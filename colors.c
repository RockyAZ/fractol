/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:39:25 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/04 17:39:26 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color_1(t_thread *thr, int p, int i)
{
	if (thr->color_id == 0)
	{
		thr->img_ptr[p] = 256 * (i < thr->iter);
		thr->img_ptr[++p] = 255 * (i < thr->iter);
		thr->img_ptr[++p] = 255 * (i < thr->iter);
	}
	else if (thr->color_id == 1)
	{
		thr->img_ptr[p] = (255 / (i + 1));
		thr->img_ptr[++p] = 255 / (i + 1);
		thr->img_ptr[++p] = 255 / (i + 1);
	}
	else if (thr->color_id == 2)
	{
		thr->img_ptr[p] = (255 % (i + 1));
		thr->img_ptr[++p] = 20 / (i + 1);
		thr->img_ptr[++p] = 510 % (i + 1);
	}
}

void	set_color_2(t_thread *thr, int p, int i)
{
	if (thr->color_id == 3)
	{
		thr->img_ptr[p] = (128 % (i + 1));
		thr->img_ptr[++p] = 255 / (i + 1);
		thr->img_ptr[++p] = 510 % (i + 1) * (i < thr->iter);
	}
	else if (thr->color_id == 4)
	{
		thr->img_ptr[p] = (i % 256);
		thr->img_ptr[++p] = 255 / (i + 1);
		thr->img_ptr[++p] = 255 * (i < thr->iter);
	}
	else if (thr->color_id == 5)
	{
		thr->img_ptr[p] = thr->zoom * (thr->mouse.x + thr->mouse.y) / (i + 1);
		thr->img_ptr[++p] = (255 * ((thr->mouse.x + 1) + (thr->mouse.y + 1)) / (i + 1));
		thr->img_ptr[++p] = (300 * ((thr->mouse.x + 1) + (thr->mouse.y + 1)) / (i + 1));
	}
}

void	what_color(t_thread *thr, int p, int i)
{
	if (thr->color_id >= 0 || thr->color_id <= 2)
		set_color_1(thr, p, i);
	if (thr->color_id >= 3 || thr->color_id <= 5)
		set_color_2(thr, p, i);
}