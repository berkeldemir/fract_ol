/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:53:25 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 15:35:56 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <X11/keysym.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./mlx/mlx.h"

# define W 550.0
# define H 550.0
# define MAX_IT 294
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ERRARG "Invalid argument count/value.\n\
-----------------------------------\n\
Sets :\e[1;31m mandelbrot, julia, feature\e[0;31m\n\
Usage:\e[1;31m ./fractol <set_name>\e[0;31m\n\
\e[2;31mTip  : You can choose real and \n\
imaginer parts of c for Julia!\n\
ex: ./fractal julia 0.365 0.365\n"
# define ERRMLC "Malloc failed."
# define ERRMOK "Hope you enjoy!"

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_app
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*ptr;
	int				bpp;
	int				size;
	int				endian;
	char			set;
	double			v1;
	double			v2;
	int				x;
	int				y;
	t_complex		z;
	t_complex		c;
	double			o_x;
	double			o_y;
	int				palette;
	int				center;
	double			max_r;
	double			max_i;
	double			min_r;
	double			min_i;
}	t_app;

void	banner(void);
int		ft_printf(const char *str, ...);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
double	ft_atod(char *s);
int		ft_isnum(char *s);
int		get_color(t_app *i, int j);
void	hook(t_app *app);
void	init(t_app *app);
void	draw(t_app *app);
void	move(t_app *app, int key);
void	zoom(t_app *app, char io, int x, int y);
void	center(t_app *app, int x, int y);
void	mandelbrot(t_app *i);
void	julia(t_app *i);
void	rejulia(t_app *app, int key);
void	feature(t_app *i);
int		quit_app(t_app *app, char *msg);

#endif