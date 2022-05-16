/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:26:51 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/21 22:17:53 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char*)s1;
	s21 = (unsigned char*)s2;
	while (*s11 != '\0' && *s11 == *s21)
	{
		s11++;
		s21++;
	}
	return (*s11 - *s21);
}
