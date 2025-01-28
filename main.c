/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:48:53 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:32 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_app	*app;

	app_init(app);
	app_hooks(app);
//	mlx_destroy_window(app->mlx, app->win);
//	mlx_destroy_display(app->mlx);
	return (0);
}
