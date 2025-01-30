/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:51:33 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/30 15:34:05 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifdef __MAC__
#  include "./ml-mac/mlx.h"
# else
#  include "./mlx/mlx.h"
# endif

# define WID 1200
# define HEI 800

typedef struct s_img
{
	int		fractal;
	// 1: Mandelbrot
	// 2: Julia
	// 3: Burning Ship
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	ox;
	double	oy;
	double	zoom;
	int		max_it;
}	t_img;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*ptr;
	int		bpp;
	int		size;
	int		endian;
}	t_app;

int		ft_printf(const char *str, ...);
void	img_init(t_img *img);
void	app_init(t_app *app);
void	app_hooks(t_app *app);

#endif