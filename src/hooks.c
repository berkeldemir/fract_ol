/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 14:07:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	destroy(t_app *app)
{
	quit_app(app, MSG_OK);
	return (0);
}

static int	key(int key, t_app *app)
{
	if (key == XK_Escape)
		quit_app(app, MSG_OK);
	else if (key == XK_Left || key == XK_a || key == XK_A || \
	key == XK_Right || key == XK_d || key == XK_D || \
	key == XK_Up || key == XK_w || key == XK_W || \
	key == XK_Down || key == XK_s || key == XK_S)
		move(app, key);
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
	else
		return (1);
	draw(app);
	return (0);
}

void	hook(t_app *app)
{
	mlx_hook(app->win, KeyPress, KeyPressMask, key, app);
	mlx_hook(app->win, ButtonPress, ButtonPressMask, mouse, app);
	mlx_hook(app->win, DestroyNotify, 0, destroy, app);
}
