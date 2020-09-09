/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nslughor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:34:15 by nslughor          #+#    #+#             */
/*   Updated: 2019/09/21 19:35:37 by nslughor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_addlist(t_fd **mfd, const int fd, char *buf)
{
	char		*str;
	t_fd		*new;

	new = *mfd;
	while (new && new->fd != fd)
		new = new->next;
	if (!new)
	{
		new = (t_fd*)malloc(sizeof(t_fd));
		new->str = ft_strnew(0);
		new->fd = fd;
		new->next = *mfd;
		*mfd = new;
	}
	str = new->str;
	new->str = ft_strjoin(new->str, buf);
	free(str);
	return (new->str);
}

static int		ft_exit_line(char **line, t_fd *mfd, const int fd)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!mfd)
		return (0);
	while (mfd && mfd->fd != fd)
		mfd = mfd->next;
	while (mfd->str[i] != '\0' && mfd->str[i] != '\n')
		i++;
	tmp = mfd->str;
	*line = ft_strsub(mfd->str, 0, i);
	mfd->str = (ft_strlen(mfd->str) > ft_strlen(*line))
			? ft_strdup(&(mfd->str[i + 1])) : NULL;
	free(tmp);
	return (1);
}

static int		ft_dellist(t_fd **mfd, const int fd)
{
	t_fd		*tmp;
	t_fd		*clean;

	tmp = *mfd;
	if (tmp->fd != fd)
	{
		while (tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;
		clean = tmp->next;
		tmp->next = clean->next ? clean->next : NULL;
		free(clean);
	}
	else
	{
		*mfd = tmp->next;
		free(tmp);
	}
	return (0);
}

static int		ft_null(t_fd *mfd, const int fd, int ret)
{
	while (mfd && mfd->fd != fd)
		mfd = mfd->next;
	if (!mfd)
		return (-1);
	if (!ret && (mfd->str == NULL || mfd->str[0] == '\0'))
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static t_fd *mfd;
	int			ret;
	int			prov;

	if (!line || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(ft_addlist(&mfd, fd, buf), '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if ((prov = ft_null(mfd, fd, ret)))
		return (prov == -1 ? 0 : (ft_dellist(&mfd, fd)));
	return (ft_exit_line(line, mfd, fd));
}
