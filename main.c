/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:48:53 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/11 19:20:08 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quit_app(t_app *app, t_img *img, char *mssg)
{
	// do all the free thing here
	exit(0);	
}

int	main(int ac, char **av)
{
	t_app	*app;
	t_img	*img;

	if (!av[1][0])
		return (ft_printf("what"), 1);
	app = malloc(sizeof(t_app));
	img = malloc(sizeof(t_img));
	if (!app || !img)
		return (1);

	app_init(app);
	if (img_init(img, av[1]) == -1)
		quit_app(app, img, "invalid argument count/value.");
	app_hooks(app);
	mlx_loop(app->mlx);
//	mlx_destroy_window(app->mlx, app->win);
//	mlx_destroy_display(app->mlx);
	return (0);
}
