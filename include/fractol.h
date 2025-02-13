/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:53:25 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 17:19:20 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include <pthread.h>
# include <float.h>
# include "./mlx/mlx.h"

# define W 1200
# define H 800
# define MAX_IT 2000

# define MAX_R 2.5
# define MAX_I 2.5
# define MIN_R -2.5
# define MIN_I -2.5

# define ESC 53
# define R 15
# define C 8

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ERRARG "Invalid argument count/value. ./fractol <mandelbrot/julia>"
# define ERRMLC "Malloc failed."
# define ERR

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*ptr;
	int			bpp;
	int			size;
	int			endian;
	char		set;
	double		v1;
	double		v2;
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;
	double		offset_x;
	double		offset_y;
	int			palette;
	double		zoom;
}	t_app;

int		ft_printf(const char *str, ...);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isnum(char *s);
int		quit_app(t_app *app, char *msg);
void	hook(t_app *app);
void	init(t_app *app);
int		get_color(t_app *i, int j);
void	mandelbrot(t_app *app);

#endif