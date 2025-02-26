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

static int	more_key(int key, t_app *app)
{
	if (key == XK_5 || key == 65437)
		app->palette = 4;
	else if (key == XK_6 || key == 65432)
		app->palette = 5;
	else if (key == 42 || key == 65451)
		zoom(app, 'i', W / 2, H / 2);
	else if (key == 45 || key == 65453)
		zoom(app, 'o', W / 2, H / 2);
	else if (key == XK_r || key == XK_R)
		init(app);
	else if (key == XK_h || key == XK_H)
		banner();
	else if (key == XK_c)
		app->palette++;
	else if (key == XK_z || key == XK_Z)
		app->center++;
	else
		return (1);
	return (0);
}

static int	key(int key, t_app *app)
{
	if (key == XK_Escape || key == XK_q)
		quit_app(app, MSG_OK);
	else if (key == XK_1 || key == 65436)
		app->palette = 0;
	else if (key == XK_2 || key == 65433)
		app->palette = 1;
	else if (key == XK_3 || key == 65435)
		app->palette = 2;
	else if (key == XK_4 || key == 65430)
		app->palette = 3;
	else if (key == XK_Left || key == XK_a || key == XK_A || \
	key == XK_Right || key == XK_d || key == XK_D || \
	key == XK_Up || key == XK_w || key == XK_W || \
	key == XK_Down || key == XK_s || key == XK_S)
		move(app, key);
	else if ((app->set == 'j') && (key == XK_o || key == XK_O || \
	key == XK_l || key == XK_L || key == XK_u || key == XK_U || \
	key == XK_j || key == XK_J))
		rejulia(app, key);
	else if (more_key(key, app) == 0)
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
	mlx_hook(app->win, KeyPress, KeyPressMask, key, app);   // LEARN ALL OF IT
	mlx_hook(app->win, ButtonPress, ButtonPressMask, mouse, app); // LEARN ALL OF IT
	mlx_hook(app->win, DestroyNotify, 0, destroy, app);
}
