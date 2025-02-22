/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:13:21 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/22 15:47:37 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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
		return (0xE71D36);
	if (j % 10 == 1)
		return (0xF9C74F);
	if (j % 10 == 2)
		return (0x90BE6D);
	if (j % 10 == 3)
		return (0xF94144);
	if (j % 10 == 4)
		return (0x90C8F0);
	if (j % 10 == 5)
		return (0xF3722C);
	if (j % 10 == 6)
		return (0xFFD166);
	if (j % 10 == 7)
		return (0x06D6A0);
	if (j % 10 == 8)
		return (0x1F2041);
	if (j % 10 == 9)
		return (0x4C5975);
	return (0xE71D36);
}

static int	palette_3(int j)
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

int	get_color(t_app *i, int j)
{
	if (i->palette % 7 == 0)
		return (palette_0(j));
	else if (i->palette % 7 == 1)
		return (palette_1(j));
	else if (i->palette % 7 == 2)
		return (palette_2(j));
	else if (i->palette % 7 == 3)
		return (palette_3(j));
	else if (i->palette % 7 == 4)
		return (((int)(255 * pow(((double)j / MAX_IT), 0.5)) << 16) | \
		((int)(255 * pow(((double)j / MAX_IT), 2)) << 8) | \
		((int)(255 * pow(((double)j / MAX_IT), 0.5))));
	else if (i->palette % 7 == 5)
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
