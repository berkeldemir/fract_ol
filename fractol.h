/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:51:33 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/24 16:44:37 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# include <stdio.h>

typedef struct s_app
{
    void    *mlx;
    void    *win;
    
}   t_app;

int	ft_printf(const char *str, ...);


#endif