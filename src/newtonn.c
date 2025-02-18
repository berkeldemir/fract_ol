/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtonn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 06:57:38 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/18 07:35:47 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


void    calc(t_app *i)
{
	int i;

	while (i < MAX_IT)
	{
		
		i++;
	}	
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
			i->z.r = i->c.r;
			i->z.i = i->c.i;
			calc(i);
			i->x++;
		}
		i->y++;
	}
}