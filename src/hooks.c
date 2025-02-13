/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 11:57:51 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	close_window(t_app *app)
{
	//mlx_destroy_window(app->mlx, app->win); // Safely destroy the window
	//mlx_destroy_display(app->mlx);  // Clean up the display
	exit(0);  // Exit the application
}


static int	key_hook(int keycode, t_app *app)
{
	ft_printf("\nkeycode: %i", keycode);
	if (keycode == 65307 || keycode == 113)
	{
		ft_printf("\nESC/Q pressed. Shutting Down.\n");
//		mlx_destroy_window(app->mlx, app->win);
		close_window(app);
	}
	if (keycode == 65300)
		return (0);
	return (0);
}

void	hooks(t_app *app)
{
	mlx_key_hook(app->win, key_hook, app->mlx);
	mlx_hook(app->win, 17, 0, close_window, &app);
	// 17 is the event for closing the window with the 'X' button
//    mlx_loop_hook(app->mlx, render, app);
}
