/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:03:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 13:46:44 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    init(t_app *app, char set, double val)
{
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, W, H, "fractol");
	app->img = mlx_new_image(app->mlx, W, H);
	app->ptr = mlx_get_data_addr(app->img,
			&app->bpp,
			&app->size,
			&app->endian);
	if (!app->win || !app->mlx || !app->img || !app->ptr)
		quit_app(app, "Init failed.");
	app->set = set;
	app->x = 0;
	app->y = 0;
	app->offset_x = 5;
	app->offset_y = 5;
	app->color = 0xFCBE11;
	app->zoom = 200;
	app->z.r = 0;
	app->z.i = 0;
	app->c.r = 0;
	app->c.i = 0;
	hooks(app);
	return ;
}
