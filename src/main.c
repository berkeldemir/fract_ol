/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 14:08:25 by beldemir         ###   ########.fr       */
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
	exit(0);
	return (0);
}

char	arg_checker(int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 3 && !(ft_strcmp(av[1], "julia")) && ft_isnum(av[2]) > 0))
			return ('Q');
	if (!ft_strcmp(av[1], "mandelbrot"))
		return ('m');
	if (!ft_strcmp(av[1], "julia"))
		return ('j');
	else
		return ('Q');
}

void draw(t_app *app, char set, double val)
{
	ft_printf("-> In draw function\n");
	if (set == 'm')
	{
		ft_printf("-> Mandelbrot is being printed\n");
		mandelbrot(app);
	}
	else if (set == 'j')
	{
		//draw_julia(app, val);
		ft_printf("-> Julia set cannot print atm\n") ;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}

int main(int ac, char **av)
{
	t_app	*app;
	char	set;
	double	val;

	set = 'Q';
	val = 0; // Mandelbrot için varsayılan değer. Aksi durumlarda julia için kullanılacak.
	set = arg_checker(ac, av);
	if (set == 'Q')
		quit_app(NULL, "Invalid argument count/value. ./fractol <mandelbrot/julia>");
	app = malloc(sizeof(t_app));
	if (!app)
		quit_app(app, "Malloc failed.");
	init(app, set, val);
	draw(app, set, val);
	mlx_loop(app->mlx);
	free(app);
}
