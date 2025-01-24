/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:51:33 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/24 22:52:39 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx-mac/mlx.h"
# include <stdio.h>

typedef struct s_app
{
    void    *mlx;
    void    *win;
    
}   t_app;

int	ft_printf(const char *str, ...);


#endif