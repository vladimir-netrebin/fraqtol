/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 07:26:02 by ivalenti          #+#    #+#             */
/*   Updated: 2020/01/25 14:41:12 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line_to_parse(char **s, char **line, int fd, int ret)
{
	char	*swap;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0' && len + 1 > len)
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		swap = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = swap;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		*swap;
	char		*buf;
	int			flag;

	if (fd < 0 || line == NULL || !(buf = (char*)malloc(BUFF_SIZE + 0)))
		return (-1);
	while ((flag = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[flag] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		swap = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = swap;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (flag < 0)
		return (-1);
	if (flag == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_line_to_parse(s, line, fd, flag));
}
