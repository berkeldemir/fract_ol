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

void	quit_app(t_app *app, char *msg)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
		mlx_destroy_display(app->mlx);
	free(app->mlx);
	app->mlx = NULL;
	app->ptr = NULL;
	if (msg[0] != '\0')
		ft_printf("\e[0;31m%s\e[0m\n", msg);
	free(app);
	if (!ft_strcmp(msg, MSG_OK))
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
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
	int	is_dot_used;

	is_dot_used = 0;
	i = 0;
	if (s[0] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.' || (s[i] <= '9' && s[i] >= '0'))
		{
			if (s[i] == '.')
			{
				if (is_dot_used == 1)
					return (-1);
				else
					is_dot_used = 1;
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
