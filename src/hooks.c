/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/17 20:27:44 by beldemir         ###   ########.fr       */
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
	printall(app);
	if (key == XK_Escape || key == XK_q)
		quit_app(app, "BYE!");
	if (key == XK_c)
		app->palette++;
	else
		return (1);
	draw(app);
	return (0);
}

static	int mouse(int key, t_app *app)
{
	if (key == 5)
		zoom_in(app);
	draw(app);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key, app);
	mlx_mouse_hook(app->win, mouse, app);
	mlx_hook(app->win, 17, 0, close_window, &app);
}
