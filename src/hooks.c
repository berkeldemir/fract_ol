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
	quit_app(app, "Hope you enjoy!\n");
}

static int	key_hook(int key, t_app *app)
{
	//ft_printf("\nkeycode: %i", keycode);
	if (key == XK_Escape || key == XK_q)
	{
		ft_printf("\nESC/Q pressed. Shutting Down.\n");
		quit_app(app, "BYE!");
		ft_printf("quit is 1 now\n");
		return (0);
	}
	if (key == XK_c)
	{
		ft_printf("app->redraw: %i\nc basildi\n", app->redraw);
		app->palette++;
		app->redraw = 1;
		ft_printf("app->redraw: %i\nc basildi\n", app->redraw);
	}
	return (0);
}

void	hook(t_app *app)
{
	mlx_key_hook(app->win, key_hook, app->mlx);
	mlx_hook(app->win, 17, 0, close_window, &app);
	mlx_loop_hook(app->mlx, loop_hook, app);
}

int	loop_hook(t_app *app)
{
	//ft_printf("app->redraw: %i\n", app->redraw);
	/*
	if (app->quit == 1)
	{
		ft_printf("hey");
		mlx_destroy_window(app->mlx, app->win);
		return (0);
	}
		*/
	//ft_printf("imin");
	app->redraw == 1;
	if (app->redraw == 1)
	{
		ft_printf("burdayim\n");
		app->palette++;
		draw(app);
		//app->redraw = 0;
	}
	return (1);
}

