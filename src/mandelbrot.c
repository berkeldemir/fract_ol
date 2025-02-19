/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/19 19:27:44 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	double	i2;
	double	r2;
	double	ri2;
	double	temp;
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		i2 = i->z.i * i->z.i;
		r2 = i->z.r * i->z.r;
		ri2 = 2.0 * i->z.i * i->z.r;
		if (i2 + r2 > 4)
			break ;
		temp = r2 - i2 + i->c.r;
		i->z.i = ri2 + i->c.i;
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
