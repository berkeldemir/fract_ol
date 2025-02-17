/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:48:20 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/17 20:07:52 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    zoom_in(t_app *i)
{
    double  a;
    double  b;
    
    ft_printf("zoom_in\n");
    a = i->x * (i->max_r - i->min_r) / W;
    b = i->y * (i->max_i - i->min_i) / H;
    
    ft_printf("zoom_in\n");
    i->max_r = a - (a - i->max_r) / ZOOM;
    i->min_r = a + (i->min_r - a) / ZOOM;
    i->max_i = b - (b - i->max_i) / ZOOM;
    i->min_i = b + (i->min_i - b) / ZOOM;
}
