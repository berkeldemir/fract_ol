/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 03:20:42 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	calc(t_app *i)
{
	double	temp;
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		if ((i->z.r * i->z.r) + (i->z.i * i->z.i) > 4)
			break ;
		temp = (i->z.r * i->z.r) - (i->z.i * i->z.i) + i->c.r;
		i->z.i = (2.0 * i->z.i * i->z.r) + i->c.i;
		i->z.r = temp;
		j++;
	}
	color(i, j);
}

void	mandelbrot(t_app *i)
{
	i->y = 0;
	while (i->y < H)
	{
		i->x = 0;
		while (i->x < W)
		{
			i->c.r = (i->x / W) * (i->max_r - i->min_r) + \
			i->min_r + i->offset_x;
			i->c.i = (i->y / H) * (i->max_i - i->min_i) + \
			i->min_i + i->offset_y;
			i->z.i = 0;
			i->z.r = 0;
			calc(i);
			i->x++;
		}
		i->y++;
	}
}
