/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 19:43:54 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	center(t_app *app, int x, int y)
{
	double	ratio_r;
	double	ratio_i;

	ratio_r = (fabs(app->min_r) + fabs(app->max_r));
	ratio_i = (fabs(app->min_i) + fabs(app->max_i));
	app->o_x += (x - (W / 2)) * (ratio_r / W);
	app->o_y += (y - (H / 2)) * (ratio_i / H);
}

void	move(t_app *app, char way)
{
	double	move_factor;

	move_factor = 0.2 * (app->max_r - app->min_r);
	if (way == 'l')
		app->o_x -= move_factor;
	else if (way == 'r')
		app->o_x += move_factor;
	else if (way == 'u')
		app->o_y -= move_factor;
	else if (way == 'd')
		app->o_y += move_factor;
}

void	zoom(t_app *app, char io, int x, int y)
{
	double	c;

	if (app->center % 2 == 1)
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
