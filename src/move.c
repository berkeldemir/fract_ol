/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 17:24:51 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void center(t_app *app, int x, int y)
{
	double	ratio_r;
	double	ratio_i;
	int	move_x;
	int move_y;

	ratio_r = (fabs(app->min_r) + fabs(app->max_r));
	ratio_i = (fabs(app->min_i) + fabs(app->max_i));
	move_x = x - (W / 2);
	move_y = y - (H / 2);
	app->min_r += (move_x) * (ratio_r / W);
	app->max_r += (move_x) * (ratio_r / W);
	app->min_i += (move_y) * (ratio_i / H);
	app->max_i += (move_y) * (ratio_i / H);
}

void	move(t_app *app, char way)
{
	double move_factor;
	
	move_factor = 0.8 * (app->max_r - app->min_r);
	if (way == 'l')
		app->o_x -= move_factor;
	else if (way == 'r')
		app->o_x += move_factor;
	else if (way == 'u')
		app->o_y -= move_factor;
	else if (way == 'd')
		app->o_y += move_factor;
}

void	zoom(t_app *app, double factor, int x, int y)
{	
	double range_r;
	double range_i;
	double new_r;
	double new_i;
    
	center(app, x, y);
	if (app->zoom == 0)
		app->zoom = 1.0;
	range_r = (app->max_r - app->min_r) * 0.04;
	range_i = (app->max_i - app->min_i) * 0.04;
	app->min_r += range_r;
	app->max_r -= range_r;
	app->min_i += range_i;
	app->max_i -= range_i;
	app->zoom *= factor;
	printf("\n\napp->zoom: %f\n\n", app->zoom);
}
/*
void	zoom_out(t_app *app, int x, int y)
{
	app->max_r += 0.08 / app->zoom;
	app->min_r -= 0.08 / app->zoom;
	app->max_i += 0.08 / app->zoom;
	app->min_i -= 0.08 / app->zoom;
    app->zoom -= 0.1;
}
*/
