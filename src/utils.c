/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:00:59 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 05:36:25 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	banner(void)
{
	ft_printf("\e[0;34m\n\\\\\\\\\\\\\\ \e[1;35mfractol by beldemir\e[0;34m \
///////\n");
	ft_printf("//////////\e[1;35m W E L C O M E \e[0;34m\
\\\\\\\\\\\\\\\\\\\\\n");
	ft_printf(" You can use WASD, direction keys \n");
	ft_printf("  and mouse wheel to move around. \n\n");
	ft_printf("------------ Shortcuts ------------\n");
	ft_printf("1 -> 5  : Select palette\n");
	ft_printf("C       : Change palette\n");
	ft_printf("Z       : Toggle mouse centred zoom\n");
	ft_printf("L Click : Center the choosen area\n");
	ft_printf("U(+)J(-): Update julia set's reel\n");
	ft_printf("O(+)L(-): Update julia set's imag\n");
	ft_printf("R       : Reload\n");
	ft_printf("H       : Help\n");
	ft_printf("Q / ESC : Quit\n\n\e[0m");
	return ;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

double	ft_atod(char *s)
{
	double	num;
	double	dec;
	int		sign;

	num = 0;
	sign = 1;
	dec = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '.' && *s != '\0')
		num = (num * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s != '\0')
	{
		dec /= 10;
		num = num + (*s++ - 48) * dec;
	}
	return (num * sign);
}

int	ft_isnum(char *s)
{
	int	i;
	int	isdotused;

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
