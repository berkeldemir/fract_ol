/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/18 02:11:24 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_w(t_app *app)
{
	int	n;

}

void    zoom_in(t_app *app)
{
    app->max_r -= 0.08 / app->zoom;
	app->min_r += 0.08 / app->zoom;
	app->max_i -= 0.08 / app->zoom;
	app->min_i += 0.08 / app->zoom;
    app->zoom++;
}
