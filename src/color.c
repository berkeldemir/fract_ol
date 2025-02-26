/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:13:21 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 14:09:28 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	palette_0(int j)
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

static int	palette_1(int j)
{
	if (j % 10 == 0)
		return (0xFF5C8D);
	if (j % 10 == 1)
		return (0xFF9A47);
	if (j % 10 == 2)
		return (0xFFDA47);
	if (j % 10 == 3)
		return (0x3E8A6F);
	if (j % 10 == 4)
		return (0x4F96FF);
	if (j % 10 == 5)
		return (0xA57BFF);
	if (j % 10 == 6)
		return (0x4F4F2F);
	if (j % 10 == 7)
		return (0xBB83FF);
	if (j % 10 == 8)
		return (0xFF3C60);
	if (j % 10 == 9)
		return (0xFF6185);
	return (0xFF5C8D);
}

static int	palette_2(int j)
{
	if (j % 10 == 0)
		return (0x7B0A3C);
	if (j % 10 == 1)
		return (0x9B0056);
	if (j % 10 == 2)
		return (0x00A8A1);
	if (j % 10 == 3)
		return (0x004E92);
	if (j % 10 == 4)
		return (0x7A3E68);
	if (j % 10 == 5)
		return (0x9A6A47);
	if (j % 10 == 6)
		return (0xD1A10A);
	if (j % 10 == 7)
		return (0x5E57A1);
	if (j % 10 == 8)
		return (0xD9D95C);
	if (j % 10 == 9)
		return (0x7B4955);
	return (0x7B0A3C);
}

static int	get_color(t_app *i, int j)
{
	if (i->palette % 6 == 0)
		return (palette_0(j));
	else if (i->palette % 6 == 1)
		return (palette_1(j));
	else if (i->palette % 6 == 2)
		return (palette_2(j));
	else if (i->palette % 6 == 3)
		return (((int)(255 * pow(((double)j / MAX_IT), 0.5)) << 16) | \
		((int)(255 * pow(((double)j / MAX_IT), 2)) << 8) | \
		((int)(255 * pow(((double)j / MAX_IT), 0.5))));
	else if (i->palette % 6 == 4)
		return (((int)(0) << 16) | \
		((int)(255 * pow(((double)j / MAX_IT), 0.5)) << 8) | \
		((int)(0)));
	else
	{
		if (j % 2 == 0)
			return (0xFFFFFF);
		return (0xAAAAAA);
	}
	return (0x000000);
}

void	color(t_app *i, int j)
{
	int		color;
	char	*pixel;

	if (j == MAX_IT)
		color = 0x000000;
	else
		color = get_color(i, j);
	pixel = i->ptr + (i->y * i->size_line + i->x * (i->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
