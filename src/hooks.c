/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 19:38:33 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	close_window(t_app *app)
{
	quit_app(app, ERRMOK);
	return (0);
}

static int	key2(int key, t_app *app)
{
	if (key == XK_r || key == XK_R)
		init(app);
	else if (key == XK_h || key == XK_H)
		banner();
	else if (key == XK_c)
		app->palette++;
	else if (key == XK_z || key == XK_Z)
		app->center++;
	else if (key == XK_m || key == XK_M)
	{
		mlx_clear_window(app->mlx, app->win);
		mandelbrot(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	}
	else if (key == XK_j || key == XK_J)
	{
		julia(app);
		mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	}
	else
		return (1);
	return (0);
}

static int	key(int key, t_app *app)
{
	if (key == XK_Escape || key == XK_q)
		quit_app(app, ERRMOK);
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
	else if (key2(key, app) == 0)
		;
	else
		return (0);
	draw(app);
	return (0);
}

static int	mouse(int key, int x, int y, t_app *app)
{
	if (key == SCROLL_UP)
		zoom(app, 'i', x, y);
	else if (key == SCROLL_DOWN)
		zoom(app, 'o', x, y);
	else if (key == 1)
		center(app, x, y);
	else
		return (1);
	draw(app);
	return (0);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key, app);
	mlx_mouse_hook(app->win, mouse, app);
	mlx_hook(app->win, 17, 0, close_window, app);
}
