/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:48:53 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/24 16:46:10 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int i, t_app *app)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int main(void)
{
    t_app *app;

    app->mlx = mlx_init();
    app->win = mlx_new_window(app->mlx, 800, 600, "Minilibx Penceresi");
    if (!app->win || !app->mlx)
        return (1);

    mlx_key_hook(app->win, key_hook, &app);
    mlx_loop(app->mlx);
    return (0);
}
