/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 05:04:47 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	center(t_app *i, int x, int y)
{
	i->offset_x += (x - (W / 2)) * ((i->max_r - i->min_r) / W);
	i->offset_y += (y - (H / 2)) * ((i->max_i - i->min_i) / H);
}

void	move(t_app *app, int key)
{
	double	c;

	c = 0.2 * (app->max_r - app->min_r);
	if (key == XK_Left || key == XK_a || key == XK_A)
		app->offset_x -= c;
	else if (key == XK_Right || key == XK_d || key == XK_D)
		app->offset_x += c;
	else if (key == XK_Up || key == XK_w || key == XK_W)
		app->offset_y -= c;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		app->offset_y += c;
}

void	zoom(t_app *app, char io, int x, int y)
{
	double	c;

	if (app->center % 2 == 1 && io == 'i')
		center(app, x, y);
	c = 0.2 * (app->max_r - app->min_r);
	if (io == 'i')
	{
		app->min_r += c;
		app->min_i += c;
		app->max_r -= c;
		app->max_i -= c;
	}
	else if (io == 'o')
	{
		app->min_r -= c;
		app->min_i -= c;
		app->max_r += c;
		app->max_i += c;
	}
}
