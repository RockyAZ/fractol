/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:34:16 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/18 17:34:17 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 800

# define WHITE 0xFFFFFF
# define BLACK 0x000000

#include "./libft/libft.h"
#include <mlx.h>
#include <math.h>
//#include <pthread.h>

typedef struct	s_mandel
{
	int			lim_x[2];
	int			lim_y[2];
}				t_mandel;

typedef struct	s_win
{
    void		*mlx_ptr;
	void		*win_ptr;
	int			center_x;
	int			center_y;	
}				t_win;

void	mandelbrot(t_win *win);

#endif
