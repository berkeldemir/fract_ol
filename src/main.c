/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 17:22:44 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	quit_app(t_app *app, char *msg)
{
	/*if (app)
	{
		// FREE ANYTTHING
	}
	else
	*/

	if (msg[0] == '\0')
		;
	else
		ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
	return (0);
}

static double ft_atod(char *s)
{
	// Edit.
	return (0.0);
}

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia")) && ft_isnum(av[2]) > 0))
			quit_app(app, ERRARG);
	if (!ft_strcmp(av[1], "mandelbrot"))
		app->set = 'm';
	else if (!ft_strcmp(av[1], "julia"))
		app->set = 'j';
	else
		ft_printf("WTF\n");
	if (ac == 4)
		app->v1 = ft_atod(av[2]);
		app->v2 = ft_atod(av[3]);
}

static void draw(t_app *app)
{
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

	look(app, ac, av);
	init(app);
	hook(app);
	draw(app);
	mlx_loop(app->mlx);
	//free_all(app);
}
