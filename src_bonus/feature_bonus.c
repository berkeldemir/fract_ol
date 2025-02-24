/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tornado.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:07:54 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 05:00:32 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

static void	calc(t_app *i)
{
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		if ((i->z.i * i->z.i + i->z.r * i->z.r) > 64)
			break ;
		i->z.r = (i->z.r * i->z.r - i->z.i * i->z.i) - i->c.r;
		i->z.i = (-2 * i->z.r * i->z.i + i->c.i);
		j++;
	}
	color(i, j);
}

void	feature(t_app *i)
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
