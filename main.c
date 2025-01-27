/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:48:53 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/27 12:52:29 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_app *app)
{
	ft_printf("\nkeycode: %i", keycode);
	if (keycode == 65307)
	{
		ft_printf("ESC pressed.");
		mlx_destroy_window(app->mlx, app->win);
		ft_printf("a");
		exit(0);
	}
	return (0);
}

int close_window(t_app *app)
{
    mlx_destroy_window(app->mlx, app->win);  // Safely destroy the window
    mlx_destroy_display(app->mlx);  // Clean up the display
    exit(0);  // Exit the application
}

int main(void)
{
	t_app	*app;

	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, 800, 600, "berxme");
	if (!app->win || !app->mlx)
		return (1);
	mlx_key_hook(app->win, key_hook, app->mlx);
	mlx_hook(app->win, 17, 0, close_window, &app);
	// 17 is the event for closing the window with the 'X' button
	mlx_loop(app->mlx);
	
    mlx_destroy_window(app->mlx, app->win);  
    mlx_destroy_display(app->mlx); 
	return (0);
}
