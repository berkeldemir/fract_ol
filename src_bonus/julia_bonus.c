/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/24 11:35:39 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

static void	calc(t_app *i)
{
	double	temp;
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		if ((i->z.r * i->z.r) + (i->z.i * i->z.i) > 64)
			break ;
		temp = (i->z.r * i->z.r) - (i->z.i * i->z.i) + i->c.r;
		i->z.i = (2.0 * i->z.i * i->z.r) + i->c.i;
		i->z.r = temp;
		j++;
	}
	color(i, j);
}

void	julia(t_app *i)
{
	i->y = 0;
	while (i->y < H)
	{
		i->x = 0;
		while (i->x < W)
		{
			i->c.r = i->v1;
			i->c.i = i->v2;
			i->z.i = (i->y / (double)H) * (i->max_i - i->min_i) \
			+ i->min_i + i->offset_y;
			i->z.r = (i->x / (double)W) * (i->max_r - i->min_r) \
			+ i->min_r + i->offset_x;
			calc(i);
			i->x++;
		}
		i->y++;
	}
}

void	rejulia(t_app *app, int key)
{
	double	shift;

	shift = 0.04;
	if (key == XK_o || key == XK_O)
		app->v2 += shift;
	else if (key == XK_l || key == XK_L)
		app->v2 -= shift;
	else if (key == XK_u || key == XK_U)
		app->v1 += shift;
	else if (key == XK_j || key == XK_J)
		app->v1 -= shift;
	draw(app);
	ft_printf("\e[3;32m");
	ft_printf("-----Julia set has been updated.----|\n");
	ft_printf("| Reel: ");
	ft_printf("%i.%i", (int)app->v1, \
	(int)((app->v1 - (int)app->v1) * 10000000));
	ft_printf(" | Imag: ");
	ft_printf("%i.%i", (int)app->v2, \
	(int)((app->v2 - (int)app->v2) * 10000000));
	ft_printf(" |\n");
	ft_printf("'-----------------------------------'\n");
	ft_printf("\e[0;m");
}
