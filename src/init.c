/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:03:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/18 05:10:44 by beldemir         ###   ########.fr       */
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
		app->win = mlx_new_window(app->mlx, W, H, "fract-ol by beldemir");
	if (!app->win)
		quit_app(app, ERRMLC);
	if (!app->img)
		app->img = mlx_new_image(app->mlx, W, H);
	if (!app->img)
		quit_app(app, ERRMLC);
	if (!app->ptr)
		app->ptr = mlx_get_data_addr(app->img,
				&app->bpp,
				&app->size,
				&app->endian);
	if (!app->ptr)
		quit_app(app, ERRMLC);
	return ;
}

void    init(t_app *app)
{
	init_mlx(app);
	if (!app->v1 || !app->v2)
	{
		app->v1 = -0.8;
		app->v2	= 0.156;
	}
	app->x = 0;
	app->y = 0;
	app->o_x = 0;
	app->o_y = 0;
	app->palette = 0;
	app->z.r = 0;
	app->z.i = 0;
	app->c.r = 0;
	app->c.i = 0;
	app->min_r = -1.2;
	app->min_i = -1.2;
	app->max_r = 1.2;
	app->max_i = 1.2;
	app->zoom = 1;
	//printall(app);
	return ;
}
