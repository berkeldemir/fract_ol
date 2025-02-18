/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:45 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/18 06:45:26 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	color(t_app *i, int iter)
{
	int		col;
	char	*pixel;

	if (iter == MAX_IT)
		col = 0x000000;
	else
		col = get_color(i, iter);
	pixel = i->ptr + (i->y * i->size + i->x * (i->bpp / 8));
	*(unsigned int *)pixel = col;
}

static void calc2(t_app *i)
{
	
}

static void	calc(t_app *i)
{
	int		iter;
	double	tol = 1e-6;
	double	zr, zi;
	double	zr2, zi2;
	double	z3r, z3i;
	double	f_r, f_i;
	double	fp_r, fp_i;
	double	denom;
	double	delta_r, delta_i;

	/* Initialize z = c */
	i->z.r = i->c.r;
	i->z.i = i->c.i;
	iter = 0;
	while (iter < MAX_IT)
	{
		zr = i->z.r;
		zi = i->z.i;
		/* Compute z^2 = (zr^2 - zi^2, 2*zr*zi) */
		zr2 = zr * zr - zi * zi;
		zi2 = 2 * zr * zi;
		/* Compute z^3 = z^2 * z */
		z3r = zr2 * zr - zi2 * zi;
		z3i = zr2 * zi + zi2 * zr;
		/* f(z)= z^3 - 1 */
		f_r = z3r - 1.0;
		f_i = z3i;
		/* f'(z)= 3*z^2 */
		fp_r = 3 * (zr * zr - zi * zi);
		fp_i = 3 * (2 * zr * zi);
		denom = fp_r * fp_r + fp_i * fp_i;
		if (denom == 0)
			break;
		/* Newton step: z = z - f(z)/f'(z) */
		delta_r = (f_r * fp_r + f_i * fp_i) / denom;
		delta_i = (f_i * fp_r - f_r * fp_i) / denom;
		i->z.r = zr - delta_r;
		i->z.i = zi - delta_i;
		/* Check convergence: if |f(z)| < tol, exit */
		if (sqrt(f_r * f_r + f_i * f_i) < tol)
			break;
		iter++;
	}
	color(i, iter);
}

void	newton(t_app *i)
{
	i->y = 0;
	while (i->y < H)
	{
		i->x = 0;
		while (i->x < W)
		{
			i->c.r = ((double)i->x / W) * (i->max_r - i->min_r) + i->min_r;
			i->c.i = ((double)i->y / H) * (i->max_i - i->min_i) + i->min_i;
			calc(i);
			i->x++;
		}
		i->y++;
	}
}

