/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:42:15 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 17:51:48 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		j;
	char	*begin;
	char	*end;

	j = 0;
	if (!s)
		return (NULL);
	begin = NULL;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	begin = (char*)&s[j];
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	end = (char*)&s[j];
	j = ft_strlen(begin) - ft_strlen(end) + 1;
	s1 = (char*)malloc(j + 1);
	if (!s1)
		return (NULL);
	s1 = ft_strncpy(s1, begin, j);
	s1[j] = '\0';
	return (s1);
}
