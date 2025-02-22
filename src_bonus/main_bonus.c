/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 15:47:29 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	quit_app(t_app *app, char *msg)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
		mlx_destroy_display(app->mlx);
	free(app->mlx);
	app->mlx = NULL;
	app->ptr = NULL;
	if (msg[0] == '\0')
		;
	else
		ft_printf("\e[0;31m%s\e[0m\n", msg);
	free(app);
	exit(EXIT_FAILURE);
	return (0);
}

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
	ft_memset((void *)app, 0, sizeof(t_app));
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
	quit_app(app, ERRMOK);
	return (0);
}
