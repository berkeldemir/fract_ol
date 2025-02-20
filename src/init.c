/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:03:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 05:30:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_mlx(t_app *app)
{
	if (!app->mlx)
		app->mlx = mlx_init();
	if (!app->mlx)
		quit_app(app, ERRMLC);
	if (!app->win)
		app->win = mlx_new_window(app->mlx, (int)W, (int)H, \
		"fract-ol by beldemir");
	if (!app->win)
		quit_app(app, ERRMLC);
	if (!app->img)
		app->img = mlx_new_image(app->mlx, (int)W, (int)H);
	if (!app->img)
		quit_app(app, ERRMLC);
	app->ptr = mlx_get_data_addr(app->img, \
	&app->bpp, &app->size, &app->endian);
	if (!app->ptr)
		quit_app(app, ERRMLC);
	return ;
}

void	init(t_app *app)
{
	init_mlx(app);
	app->v1 = 0.4;
	app->v2 = 0.4;
	app->x = 0;
	app->y = 0;
	app->o_x = 0;
	app->o_y = 0;
	app->palette = 0;
	app->z.r = 0;
	app->z.i = 0;
	app->c.r = 0;
	app->c.i = 0;
	app->min_r = -1.3;
	app->min_i = -1.3;
	app->max_r = 1.3;
	app->max_i = 1.3;
	app->center = 1;
	return ;
}
