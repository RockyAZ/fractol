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

# define WIDTH 1000
# define HEIGHT 800

# define THREAD 1

# define WHITE 0xFFFFFF
# define BLACK 0x000000

#include "./libft/libft.h"
#include "keys.h"
#include <mlx.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
typedef struct		s_image
{
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned char	*ptr;
}					t_image;

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_julia
{
	double			rn[2];
	double			in[2];
}					t_julia;

typedef struct		s_mandel
{
	double			rn[2];
	double			in[2];
	double			buf_r;
	double			buf_i;
}					t_mandel;

typedef struct		s_thread
{
	int				y;
	int				lim_y;
	int				size_line;
	unsigned char	*img_ptr;
	int				iter;
	double			zoom;
	double			move_x;
	double			move_y;
	t_mouse			mouse;
	double			buf_r;
	double			buf_i;
}					t_thread;
/*
**	win->fract_id == 1 -> JULIA
**	win->fract_id == 2 -> MANDELBROT
*/

typedef struct		s_win
{
    void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	int				fract_id;
	t_thread		thread[THREAD];
	////////////////////////
}					t_win;

/*
**	main functions
*/
void				mandelbrot(t_win *win);
void				julia(t_win *win);
int					ft_exit(t_win *win);

/*
** drawing
*/
void				prepare_draw(t_win *win);
void				set_pixel(int x, int y, int i, t_thread *win);
void				drawing(t_win *win);

/*
**	helper && error
*/
void				main_preparation(t_win *win, char *av);
void				error(char *str);
/*
** reboot picture by presing [R]
*/
void				make_thread(t_win *win);
/*
** mouse & keys
*/
int					mouse_move(int x, int y, t_win *win);
int					ft_keyhook(int key, t_win *win);
#endif
