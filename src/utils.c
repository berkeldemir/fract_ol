/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:00:59 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/13 14:03:28 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_atof(char *s)
{
	double	nb;
	double	dec;
	int		sign;

	nb = 0;
	sign = 1;
	dec = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s != '.' && *s != '\0')
		nb = (nb * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s != '\0')
	{
		dec /= 10;
		nb = nb + (*s++ - 48) * dec;
	}
	return (nb * sign);
}

int	ft_isnum(char *s)
{
    int i;
    int isdotused;

    isdotused = 0;
    i = 0;
	if (s[0] == '-' || s[i] == '+')
		i++;
    while (s[i])
    {
        if (s[i] == '.' || (s[i] <= '9' && s[i] >= '0'))
        {
            if (s[i] == '.')
            {
                if (isdotused == 1)
                    return (-1);
                else
                    isdotused = 1;
            }
            i++;
        }
        else
           return (-1);
    }
    return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
