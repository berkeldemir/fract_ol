/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/12 19:35:23 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	quit_app(t_app *app, char *msg)
{
	/*if (app)
	
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
		if (!(ac == 3 && !ft_strcmp(av[1], "julia") && ft_isnum(av[2]) > 0))
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
	if (set == 'm')
		draw_mandelbrot(app);
	if (set == 'j')
	{
		//draw_julia(app, val);
		return ;
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
	mlx_loop(app->mlx);
	draw(app, set, val);
	free(app);
}
