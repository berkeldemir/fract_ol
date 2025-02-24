/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/24 11:35:16 by beldemir         ###   ########.fr       */
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
