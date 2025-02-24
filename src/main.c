/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 14:05:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia")) \
			&& ft_isnum(av[2]) > 0 && ft_isnum(av[3]) > 0))
			quit_app(app, MSG_ARG);
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia"))
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			app->set = 'm';
		else
			app->set = 'j';
	}
	else
		quit_app(app, MSG_ARG);
}

void	draw(t_app *app)
{
	mlx_clear_window(app->mlx, app->win);
	if (app->set == 'm')
		mandelbrot(app);
	else if (app->set == 'j')
		julia(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_app	*app;

	app = (t_app *)malloc(sizeof(t_app));
	if (!app)
		quit_app(app, MSG_MALLOC);
	ft_memset((void *)app, 0, sizeof(t_app));
	look(app, ac, av);
	init(app);
	hook(app);
	if (ac == 4)
	{
		app->v1 = ft_atod(av[2]);
		app->v2 = ft_atod(av[3]);
	}
	draw(app);
	mlx_loop(app->mlx);
	quit_app(app, MSG_OK);
	return (0);
}
