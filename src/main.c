/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 11:29:10 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
void	printall(t_app *i)
{
	printf("\n------------------------------------------\n");
	printf("x: %i\n", i->x);
	printf("y: %i\n", i->y);
	printf("o_x: %f\n", i->o_x);
	printf("o_y: %f\n", i->o_y);
	printf("palette: %i\n", i->palette);
	printf("z.r: %f\n", i->z.r);
	printf("z.i: %f\n", i->z.i);
	printf("c.r: %f\n", i->c.r);
	printf("c.i: %f\n", i->c.i);
	printf("zoom: %f\n", i->zoom);
	printf("min_r: %f\n", i->min_r);
	printf("min_i: %f\n", i->min_i);
	printf("max_r: %f\n", i->max_r);
	printf("max_i: %f\n", i->max_i);
	printf("------------------------------------------\n");
}

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia"))
			&& ft_isnum(av[2]) > 0 && ft_isnum(av[3]) > 0))
			quit_app(app, ERRARG);
	if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "newton"))
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			app->set = 'm';
		else if (!ft_strcmp(av[1], "newton"))
			app->set = 'n';
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
	//ft_printf("-> In draw function\n");
	if (app->set == 'm')
		mandelbrot(app);
	else if (app->set == 'j')
		julia(app);
	else if (app->set == 'n')
		 ;//newton(app);
	//printall(app);
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
	return (0);
}
