/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:03:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/12 19:20:12 by beldemir         ###   ########.fr       */
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
		exit (1);
	app->set = set;
	app->x = 0;
	app->y = 0;
	app->offset_x = -1.21;
	app->offset_y = -1.21;
	app->color = 0xFCBE11;
	app->zoom = 300;
	app->z.r = 0;
	app->z.i = 0;
	app->c.r = 0;
	app->c.i = 0;
	hooks(app);
	return ;
}
