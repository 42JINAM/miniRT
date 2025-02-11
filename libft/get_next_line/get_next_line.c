/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:29:54 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 03:54:20 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	*_gnl_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (!s1 & !s2)
		return (0);
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	if (s2 < s1)
	{
		i = n;
		while (i > 0)
		{
			tmp_s1[i - 1] = tmp_s2[i - 1];
			i --;
		}
	}
	else if (s2 > s1)
	{
		i = -1;
		while (++i < n)
			tmp_s1[i] = tmp_s2[i];
	}
	return (s1);
}

static char	*_gnl_makeline(t_list *node, size_t size,
						char **line, size_t option)
{
	const size_t	res_len = node->last_len + size + 1;
	char			*res;

	res = malloc(sizeof(char) * (res_len));
	if (*line)
	{
		_gnl_memmove(res, *line, node->last_len);
		free(*line);
	}
	_gnl_memmove(&res[node->last_len],
		&node->buff[node->eol - size + 1], size + 1);
	res[res_len - 1] = 0;
	node->last_len += size;
	if (option == IS_END)
	{
		node->last_len = 0;
		node->eol ++;
	}
	node->new_len = 1;
	*line = res;
	return (res);
}

static void	_gnl_getline(int fd, t_list *node, size_t size)
{
	node->rbytes = read(fd, node->buff, size);
	node->eol = 0;
	node->new_len = 1;
}

static void	*_gnl_clear(t_list *node, char *line)
{
	if (line)
		free(line);
	node->eol = BUFFER_SIZE;
	node->last_len = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	node = {"", BUFFER_SIZE,
		BUFFER_SIZE, 0, 0};
	char			*line;

	line = (void *) 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (_gnl_clear(&node, line));
	while (1)
	{
		if (node.eol == BUFFER_SIZE)
			_gnl_getline(fd, &node, BUFFER_SIZE);
		if (node.rbytes <= 0 || ((size_t)node.rbytes == node.eol))
		{
			_gnl_clear(&node, NULL);
			return (line);
		}
		if (node.buff[node.eol] == '\n')
			return (_gnl_makeline(&node, node.new_len, &line, IS_END));
		if (node.eol == (size_t)node.rbytes - 1)
			line = _gnl_makeline(&node, node.new_len, &line, NOT_END);
		node.eol ++;
		node.new_len ++;
	}
}
