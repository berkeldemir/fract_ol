/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:58:36 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/11 19:47:11 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	img_init(t_img *img, char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
		img->set = 1;
	else if (!ft_strcmp(fractal, "julia"))
		img->set = 2;
	else if  (!ft_strcmp(fractal, "burningship"))
		img->set = 3;
	else
		return (-1);
	img->x = 0;
	img->y = 0;
	img->color = 0xFCBE11;
	img->zoom = 300;
	img->z.r = -1.21;
	img->z.i = -1.21;
	img->c.r = 0;
	img->c.i = -1.21;
	img->max_it = 42;
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
}
