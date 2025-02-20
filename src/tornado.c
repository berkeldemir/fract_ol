/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tornado.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:07:54 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 04:19:47 by beldemir         ###   ########.fr       */
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
/*
static void complex_pow(double r, double i, double exponent, double *new_r, double *new_i) {
    double mag = sqrt(r * r + i * i);
    double theta = atan2(i, r);

    double new_mag = pow(mag, exponent);
    double new_theta = exponent * theta;

    *new_r = new_mag * cos(new_theta);
    *new_i = new_mag * sin(new_theta);
}
*/

static void	calc(t_app *i)
{
	int		j;

	j = 0;
	while (j < MAX_IT)
	{
		double modulus = sqrt(i->z.r * i->z.r + i->z.i * i->z.i);
		double arg = atan2(i->z.i, i->z.r);
		double p = 2.3; // Try changing this value

		i->z.r = pow(modulus, p) * cos(p * arg) - i->c.r;
		i->z.i = pow(modulus, p) * sin(p * arg) - i->c.i;

		if ((i->z.i * i->z.i) + (i->z.r * i->z.r) > 36)
			break ;
		j++;
	}
	color(i, j);
}

void	tornado(t_app *i)
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
			i->z.i = 0.0;
			i->z.r = 0.0;
			calc(i);
			i->x++;
		}
		i->y++;
	}

	ft_printf("done\n");
}
