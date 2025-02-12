/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/12 19:20:23 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	put_color(t_app *app, int color)
{
	int	*buff;
	buff = app->ptr;
	buff[(app->y * app->size / 4) + app->x] = color; 
}

static int	calc_mandelbrot(t_app *app)
{
	int		i;
	double	temp;

	i = 0;
	app->c.r = (app->x / app->zoom) + app->offset_x;
	app->c.i = (app->y / app->zoom) + app->offset_y;
	while (++i < MAX_IT)
	{
		temp = app->z.r * app->z.r - app->z.i * app->z.i + app->c.r;
		app->z.i = 2.0 * app->z.r * app->z.i + app->c.i;
		app->z.r = temp;
		if (app->z.r * app->z.r + app->z.i * app->z.i >= __DBL_MAX__)
			break;
	}
	if (i == MAX_IT)
		put_color(app, 0x000000);
	else
		put_color(app, (app->color * i));
}

void	draw_mandelbrot(void *void_app)
{
	t_app	*app;
	
	app = (t_app *)void_app;
	while(app->x < H)
	{
		while (app->y < W)
		{
			calc_mandelbrot(app);
			app->y++;
		}
		app->x++;
		app->y = 0;
	}
	app->x = 0;
	app->y = 0;
}
