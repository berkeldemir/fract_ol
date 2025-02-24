/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:13:21 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/24 11:35:08 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	palette(int j)
{
	if (j % 10 == 0)
		return (0xE39090);
	if (j % 10 == 1)
		return (0xE3C290);
	if (j % 10 == 2)
		return (0xD4E390);
	if (j % 10 == 3)
		return (0x94E390);
	if (j % 10 == 4)
		return (0x90e3b9);
	if (j % 10 == 5)
		return (0x90D9E3);
	if (j % 10 == 6)
		return (0x90B2E3);
	if (j % 10 == 7)
		return (0x9B90E3);
	if (j % 10 == 8)
		return (0xC390E3);
	if (j % 10 == 9)
		return (0xE390B7);
	return (0xE39090);
}

void	color(t_app *i, int j)
{
	int		color;
	char	*pixel;

	if (j == MAX_IT)
		color = 0x000000;
	else
		color = palette(j);
	pixel = i->ptr + (i->y * i->size_line + i->x * (i->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
