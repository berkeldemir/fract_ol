/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 21:48:34 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	close_window(t_app *app)
{
	quit_app(app, "Hope you enjoy!");
}

static int	key_hook(int keycode, t_app *app)
{
	ft_printf("\nkeycode: %i", keycode);
	if (keycode == 65307 || keycode == 113)
	{
		ft_printf("\nESC/Q pressed. Shutting Down.\n");
		quit_app(app, "BYE!");
	}
	if (keycode == 99)
	{
		app->palette++;
		mlx_clear_window(app->mlx, app->win);
		sleep(3);
		draw(app);
	}
	return (0);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key_hook, app->mlx);
	mlx_hook(app->win, 17, 0, close_window, &app);
	// 17 is the event for closing the window with the 'X' button
//    mlx_loop_hook(app->mlx, render, app);
}
