/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:48:53 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/24 23:07:47 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int	key_hook(int i, t_app *app)
//{
//	printf("Hello from key_hook!\n");
//	return (0);
//}

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Minilibx Penceresi");
    if (!win || !mlx)
        return (1);

    //mlx_key_hook(app->win, key_hook, &app);
    mlx_loop(mlx);
    return (0);
}
