/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:51:33 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/28 16:11:54 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WID 1200
# define HEI 800

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

typedef struct s_img
{
	t_app	*app;
	
}	t_img;

int		ft_printf(const char *str, ...);
void	img_init(t_img *img);
void	app_init(t_app *app);
void	app_hooks(t_app *app);

#endif