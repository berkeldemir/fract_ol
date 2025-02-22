/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feature_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:07:54 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 15:47:15 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

static void	color(t_app *i, int j)
{
	int		color;
	char	*pixel;

	if (j == MAX_IT)
		color = 0x000000;
	else
		color = get_color(i, j);
	pixel = i->ptr + (i->y * i->size + i->x * (i->bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	calc(t_app *i)
{
	double	a;
	double	b;
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		a = (i->z.r * i->z.r - i->z.i * i->z.i) - i->c.r;
		b = (-2 * i->z.r * i->z.i + i->c.i);
		if ((i->z.i * i->z.i + i->z.r * i->z.r) > 64)
			break ;
		i->z.r = a;
		i->z.i = b;
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
			i->min_r + i->o_x;
			i->c.i = (i->y / H) * (i->max_i - i->min_i) + \
			i->min_i + i->o_y;
			i->z.i = 0;
			i->z.r = 0;
			calc(i);
			i->x++;
		}
		i->y++;
	}
}
