/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 15:47:35 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	center(t_app *app, int x, int y)
{
	double	ratio_r;
	double	ratio_i;

	ratio_r = (fabs(app->min_r) + fabs(app->max_r));
	ratio_i = (fabs(app->min_i) + fabs(app->max_i));
	app->o_x += (x - (W / 2)) * (ratio_r / W);
	app->o_y += (y - (H / 2)) * (ratio_i / H);
}

void	move(t_app *app, int key)
{
	double	move_factor;

	move_factor = 0.2 * (app->max_r - app->min_r);
	if (key == XK_Left || key == XK_a || key == XK_A)
		app->o_x -= move_factor;
	else if (key == XK_Right || key == XK_d || key == XK_D)
		app->o_x += move_factor;
	else if (key == XK_Up || key == XK_w || key == XK_W)
		app->o_y -= move_factor;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		app->o_y += move_factor;
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
	else
		return ;
}
