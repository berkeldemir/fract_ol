/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 16:09:48 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

static int	close_window(t_app *app)
{
	quit_app(app, ERRMOK);
}

static int	key(int key, t_app *app)
{
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
	else if (key == XK_Left || key == XK_a || key == XK_A)
		move(app, 'l');
	else if (key == XK_Right || key == XK_d || key == XK_D)
		move(app, 'r');
	else if (key == XK_Up || key == XK_w || key == XK_W)
		move(app, 'u');
	else if (key == XK_Down || key == XK_s || key == XK_S)
		move(app, 'd');
	else if (key == XK_r)
		init(app);
	else
	{
		printall(app);
		return (1);
	}
	draw(app);
	return (0);
}

static	int mouse(int key, int x, int y, t_app *app)
{
	ft_printf("key %i\n", key);
	if (key == SCROLL_UP)
		zoom(app, 1.5, x, y);
	else if (key == SCROLL_DOWN)
		zoom(app, 0.5, x, y);
	else if (key == 1)
		center(app, x, y);
	else
		return (1);
	printall(app);
	draw(app);
	return (0);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key, app);
	mlx_mouse_hook(app->win, mouse, app);
	mlx_hook(app->win, 17, 0, close_window, &app);
}
