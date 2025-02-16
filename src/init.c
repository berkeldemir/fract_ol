/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:03:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 21:45:40 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_mlx(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		quit_app(app, ERRMLC);
	app->win = mlx_new_window(app->mlx, W, H, "fract-ol by beldemir");
	if (!app->win)
		quit_app(app, ERRMLC);
	app->img = mlx_new_image(app->mlx, W, H);
	if (!app->img)
		quit_app(app, ERRMLC);
	app->ptr = mlx_get_data_addr(app->img,
			&app->bpp,
			&app->size,
			&app->endian);
	if (!app->ptr)
		quit_app(app, ERRMLC);
}

void    init(t_app *app)
{
	init_mlx(app);
	if (!app->v1 || !app->v2)
	{
		app->v1 = 1.21;
		app->v2	= 1.21;
	}
	app->x = 0;
	app->y = 0;
	app->offset_x = -0.5;
	app->offset_y = 0;
	app->palette = 0;
	app->zoom = 1;
	app->z.r = 0;
	app->z.i = 0;
	app->c.r = 0;
	app->c.i = 0;
	app->min_r = -1;
	app->min_i = -1;
	app->max_r = 1;
	app->max_i = 1;
	app->quit = 0;
	app->redraw = 0;
	return ;
}
