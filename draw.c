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
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->ptr = (unsigned char*)mlx_get_data_addr(win->img_ptr,
	&win->bpp, &win->size_line, &win->endian);
	while (i < THREAD)
	{
		win->thread[i].size_line = win->size_line;
		win->thread[i].img_ptr = win->ptr;
		i++;
	}
}

void	set_pixel(int x, int y, int i, t_thread *thr)
{
	int p;

	p = (x * 4) + (y * thr->size_line);
	what_color(thr, p, i);
	// thr->img_ptr[p] = thr->zoom * (thr->mouse.x + thr->mouse.y) / (i + 1);
	// thr->img_ptr[++p] = (255 * ((thr->mouse.x + 1) + (thr->mouse.y + 1)) / (i + 1));
	// thr->img_ptr[++p] = (300 * ((thr->mouse.x + 1) + (thr->mouse.y + 1)) / (i + 1));
//grey
	// thr->img_ptr[p] = (255 / (i + 1));//blue
	// thr->img_ptr[++p] = 255 / (i + 1);//green
	// thr->img_ptr[++p] = 255 / (i + 1);//red
//чуть более крутой фиолетовый разлом
	// thr->img_ptr[p] = (255 % (i + 1));//blue
	// thr->img_ptr[++p] = 20 / (i + 1);//green
	// thr->img_ptr[++p] = 510 % (i + 1);//red
//фиолетовый разлом но хуевый зеленый фон
	// thr->img_ptr[p] = (128 % (i + 1));
	// thr->img_ptr[++p] = 255 / (i + 1);
	// thr->img_ptr[++p] = 510 % (i + 1) * (i < thr->iter);
//умеренная наркомания
	// thr->img_ptr[p] = (i % 256);
	// thr->img_ptr[++p] = 255 / (i + 1);
	// thr->img_ptr[++p] = 255 * (i < thr->iter);
//разлитая краска
	// thr->img_ptr[p] = 256 * (i < thr->iter);
	// thr->img_ptr[++p] = 255 * (i < thr->iter);
	// thr->img_ptr[++p] = 255 * (i < thr->iter);
}

void	ft_str_window(t_win *win)
{
	char *iter;
	char *thread;

	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, RED, "FRACTAL:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 80, 0, RED, win->name);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 20, GREEN, "ITERATIONS:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 120, 20, GREEN, iter = ft_itoa(win->thread[0].iter));
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 40, BLUE, "THREADS:");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 80, 40, BLUE, thread = ft_itoa(THREAD));
	if (win->mouse_julia == 1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK, "MOUSE ON");
	else if (win->mouse_julia == -1)
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 60, PINK, "MOUSE OFF");
	free(iter);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 80, BLUE, "ZOOM:");	
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 80, BLUE, iter = ft_itoa((int)win->thread[0].zoom));
	free(iter);
	free(thread);
}

void	drawing(t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	if (win->is_text == 1)
		ft_str_window(win);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
}
