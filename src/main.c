/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 05:02:45 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia")) \
			&& ft_isnum(av[2]) > 0 && ft_isnum(av[3]) > 0))
			quit_app(app, ERRARG);
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia") \
		|| !ft_strcmp(av[1], "feature"))
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			app->set = 'm';
		else if (!ft_strcmp(av[1], "feature"))
			app->set = 'f';
		else
			app->set = 'j';
	}
	else
		quit_app(app, ERRARG);
}

void	draw(t_app *app)
{
	mlx_clear_window(app->mlx, app->win);
	if (app->set == 'm')
		mandelbrot(app);
	else if (app->set == 'j')
		julia(app);
	else if (app->set == 'f')
		feature(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_app	*app;

	app = (t_app *)malloc(sizeof(t_app));
	if (!app)
		quit_app(app, ERRMLC);
	look(app, ac, av);
	init(app);
	banner();
	hook(app);
	if (ac == 4)
	{
		app->v1 = ft_atod(av[2]);
		app->v2 = ft_atod(av[3]);
	}
	draw(app);
	mlx_loop(app->mlx);
	return (0);
}
