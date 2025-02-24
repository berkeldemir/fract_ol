/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:01:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/24 11:35:42 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	banner(void)
{
	ft_printf("\e[0;34m\n\\\\\\\\\\\\\\ \e[1;35mfractol by beldemir\e[0;34m \
///////\n");
	ft_printf("//////////\e[1;35m W E L C O M E \e[0;34m\
\\\\\\\\\\\\\\\\\\\\\n");
	ft_printf(" You can use WASD, direction keys \n");
	ft_printf("  and mouse wheel to move around. \n\n");
	ft_printf("------------ Shortcuts ------------\n");
	ft_printf("1 -> 7  : Select palette\n");
	ft_printf("C       : Change palette\n");
	ft_printf("Z       : Toggle mouse centred zoom\n");
	ft_printf("L Click : Center the choosen area\n");
	ft_printf("* and - : Zoom in/out with keyboard\n");
	ft_printf("U(+)J(-): Update julia set's reel\n");
	ft_printf("O(+)L(-): Update julia set's imag\n");
	ft_printf("R       : Reload\n");
	ft_printf("H       : Help\n");
	ft_printf("Q / ESC : Quit\n\n\e[0m");
}

static void	look(t_app *app, int ac, char **av)
{
	if (ac != 2)
		if (!(ac == 4 && !(ft_strcmp(av[1], "julia")) \
			&& ft_isnum(av[2]) > 0 && ft_isnum(av[3]) > 0))
			quit_app(app, MSG_ARG);
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
		quit_app(app, MSG_ARG);
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
		quit_app(app, MSG_MALLOC);
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
	quit_app(app, MSG_OK);
	return (0);
}
