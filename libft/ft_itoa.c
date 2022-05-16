/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:44:46 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/23 21:35:17 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_set_i(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (-1);
	if (n == -2147483648)
		return (-2);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char		*ft_special(int i)
{
	char	*s;
	int		n;
	int		j;

	n = -2147483648;
	if (i == -1)
	{
		s = ft_strnew(2);
		s[0] = '0';
		return (s);
	}
	j = 11;
	s = (char*)malloc(j);
	s[0] = '-';
	s[j] = '\0';
	while (j > 1)
	{
		j--;
		s[j] = n % (-10) * (-1) + '0';
		n /= 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = ft_set_i(n);
	if (i == -1 || i == -2)
		return (ft_special(i));
	i += (n < 0);
	s = (char*)malloc(i + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	s[i] = '\0';
	while (i && n)
	{
		i--;
		s[i] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
