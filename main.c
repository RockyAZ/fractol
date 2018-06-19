/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:20:15 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 14:20:17 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    t_win *win;

	win = (t_win*)malloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "THE WINDOW");
	win->center_x = WIDTH / 2;
	win->center_y = HEIGHT / 2;
	mandelbrot(win);
	mlx_loop(win->mlx_ptr);
}
