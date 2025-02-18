/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/18 02:14:16 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>
void	printall(t_app *i)
{
	printf("\n------------------------------------------\n");
	printf("x: %i\n", i->x);
	printf("y: %i\n", i->y);
	printf("o_x: %f\n", i->o_x);
	printf("o_y: %f\n", i->o_y);
	printf("palette: %i\n", i->palette);
	printf("z.r: %f\n", i->z.r);
	printf("z.i: %f\n", i->z.i);
	printf("c.r: %f\n", i->c.r);
	printf("c.i: %f\n", i->c.i);
	printf("min_r: %f\n", i->min_r);
	printf("min_i: %f\n", i->min_i);
	printf("max_r: %f\n", i->max_r);
	printf("max_i: %f\n", i->max_i);
	printf("------------------------------------------\n");
}

static int	close_window(t_app *app)
{
	quit_app(app, "Hope you enjoy!\n");
}

static int	key(int key, t_app *app)
{
	//printall(app);
	//ft_printf("key: %i\n", key);
	if (app->palette == 2147483647)
			app->palette = 3;
	if (key == XK_Escape || key == XK_q)
		quit_app(app, "BYE!");
	else if (key == XK_c)
			app->palette++;
	else if (key == XK_1)
		app->palette = 0;
	else if (key == XK_2)
		app->palette = 1;
	else if (key == XK_3)
		app->palette = 2;
	else if (key == XK_4)
		app->palette = 3;
	else if (key == XK_Left)
		app->o_x -= 0.08 / app->zoom;
	else if (key == XK_Right)
		app->o_x += 0.08 / app->zoom;
	else if (key == XK_Up)
		app->o_y -= 0.08 / app->zoom;
	else if (key == XK_Down)
		app->o_y += 0.08 / app->zoom;
	else if (key == XK_u)
	{
		app->zoom++;
    	app->max_r -= 0.8 / app->zoom;
		app->min_r += 0.8 / app->zoom;
		app->max_i -= 0.8 / app->zoom;
		app->min_i += 0.8 / app->zoom;
	}
	else if (key == XK_r)
		init(app);
	else
		return (1);
	draw(app);
	return (0);
}

static	int mouse(int key, t_app *app)
{
	if (key == SCROLL_UP)
		zoom_in(app);
	/*
	else if (key == 6)
		;//zoom_out(app);
	*/
	else
		return (1);
	draw(app);
	return (0);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key, app);
	mlx_mouse_hook(app->win, mouse, app);
	mlx_hook(app->win, 17, 0, close_window, &app);
}
