/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:43:39 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 09:18:08 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	quit_app(t_app *app, char *msg)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
		mlx_destroy_display(app->mlx);
	free(app->mlx);
	//free(app->ptr);
	app->mlx = NULL;
	app->ptr = NULL;
	if (msg[0] == '\0')
		;
	else
		ft_printf("%s\n", msg);
	free(app);
	exit(EXIT_FAILURE);
	return (0);
}