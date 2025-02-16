/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:43:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 21:46:49 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
static void free_app(t_app *app)
{
		free(app->mlx);
		free(app->win);
		free(app->img);
		free(app->ptr);
		free(app->bpp);
		free(app->size);
		free(app->endian);
		free(app->x);
		free(app->y);
		free(&app->offset_x);
		free(&app->offset_y);
		free(app->palette);
		free(&app->zoom);
		free(&app->z.i);
		free(&app->z.r);
		free(&app->c.i);
		free(&app->c.r);
		free(&app->z);
		free(&app->c);
		free(&app->min_r);
		free(&app->min_i);
		free(&app->max_r);
		free(&app->max_i);
		free(app);
}
*/

int	quit_app(t_app *app, char *msg)
{
	/*
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
		mlx_destroy_display(app->mlx);
	
	free(app->mlx);
	app->mlx = NULL;
	*/
	app->quit = 1;
	if (msg[0] == '\0')
		;
	else
		ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
	return (0);
}