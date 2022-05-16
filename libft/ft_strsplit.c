/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:03:10 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 13:45:55 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_clearstr(char **s)
{
	size_t	i;

	if (!s || !*s || !**s)
		return (NULL);
	i = 0;
	while (s[i] != NULL)
	{
		ft_strdel(&s[i]);
		i++;
	}
	ft_memdel((void *)(s));
	s = NULL;
	return (s);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**dict;

	i = 0;
	if (!s ||
			!(dict = (char **)ft_memalloc(sizeof(char *) * ft_cntwords(s, c))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] != c && s[len] != '\0')
				len++;
			if (!(dict[i] = ft_strncpy(ft_strnew(len), s, len)))
				return (ft_clearstr(dict));
			s += len;
			i++;
		}
		else
			s++;
	}
	dict[i] = NULL;
	return (dict);
}
