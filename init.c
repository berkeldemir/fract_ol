/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:58:36 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/28 16:11:33 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_init(t_img *img)
{
	return ;
}

void	app_init(t_app *app)
{
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, WID, HEI, "berxme");
	app->img = mlx_new_image(app->mlx, WID, HEI);
	app->ptr = mlx_get_data_addr(app->img,
			&app->bpp,
			&app->size,
			&app->endian);
	if (!app->win || !app->mlx || !app->img || !app->ptr)
		exit (1);
}

static int	key_hook(int keycode, t_app *app)
{
	ft_printf("\nkeycode: %i", keycode);
	if (keycode == 65307)
	{
		ft_printf("\nESC pressed. Shutting Down.\n");
//		mlx_destroy_window(app->mlx, app->win);
		ft_printf("a");
		exit(0);
	}
	if (keycode == 65300)
	{
		return (0);
	}
	return (0);
}

static int	close_window(t_app *app)
{
	mlx_destroy_window(app->mlx, app->win); // Safely destroy the window
	mlx_destroy_display(app->mlx);  // Clean up the display
	exit(0);  // Exit the application
}

void	app_hooks(t_app *app)
{
	mlx_key_hook(app->win, key_hook, app->mlx);
	mlx_hook(app->win, 17, 0, close_window, &app);
	// 17 is the event for closing the window with the 'X' button
	mlx_loop(app->mlx);
}
