/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:00:59 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/12 15:12:26 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(char *s)
{
    int i;
    int isdotused;

    isdotused = 0;
    while (s[i])
    {
        if (s[i] == '.' || (s[i] <= '9' && s[i] >= '0'))
        {
            if (s[i] == '.')
            {
                if (isdotused == 1)
                    return (0);
                else
                    isdotused = 1;
            }
            i++;
        }
        else
           return (0);
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
