/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 21:03:09 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double ft_atod(char *s)
{
	// Edit.
	return (0.0);
}

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia"))
			&& ft_isnum(av[2]) > 0 && ft_isnum(av[3]) > 0))
			quit_app(app, ERRARG);
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia"))
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			app->set = 'm';
		else
			app->set = 'j';
	}
	else
		quit_app(app, ERRARG);
	if (ac == 4)
	{
		app->v1 = ft_atod(av[2]);
		app->v2 = ft_atod(av[3]);
	}
}

void draw(t_app *app)
{
	mlx_clear_window(app->mlx, app->win);
	ft_printf("-> In draw function\n");
	if (app->set == 'm')
		mandelbrot(app);
	else if (app->set == 'j')
		ft_printf("-> Julia set cannot print atm\n") ;
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int main(int ac, char **av)
{
	t_app	*app;

	app = malloc(sizeof(t_app));
	if (!app)
		quit_app(app, ERRMLC);
	look(app, ac, av);
	init(app);
	hook(app);
	draw(app);
	mlx_loop(app->mlx);
	//mlx_loop_hook(app->mlx, loop_hook, app);
	//free_all(app);
}
