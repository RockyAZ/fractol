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

# define THREAD 8

# define WHITE 0xFFFFFF
# define BLACK 0x000000

#include "./libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
typedef struct		s_mandel
{
	int				lim;
	double			rn[2];
	double			in[2];
	double			buf_r;
	double			buf_i;	
}					t_mandel;

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_win
{
    void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned char	*ptr;
	int				iter;
	double			zoom;
	double			move_x;
	double			move_y;
	t_mouse			mouse;
}					t_win;

/*
**	main
*/
void				mandelbrot(t_win *win);
void				julia(t_win *win);

/*
** drawing
*/
void				prepare(t_win *win);
void				set_pixel(int x, int y, int i, t_win *win);
void				drawing(t_win *win);

/*
**	helper && error
*/
void				preparation(t_win *win, char *av);
void				error(char *str);

/*
** mouse
*/
int					mouse_move(int x, int y, t_win *win);
#endif
