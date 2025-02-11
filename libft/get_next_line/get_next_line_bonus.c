/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:29:54 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 04:08:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

static int	_gnl_getline(t_list **begin_list, t_list *node,
						char *line, size_t size)
{
	node->rbytes = read(node->fd, node->buff, size);
	if (node->rbytes < 0)
	{
		_gnl_del_node(begin_list, node);
		free(line);
		return (ERROR);
	}
	node->eol = 0;
	node->new_len = 1;
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	t_list			*node;
	char			*line;

	line = (void *) 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !_gnl_find_node(&head, &node, fd))
		return ((void *) 0);
	while (1)
	{
		if ((size_t)node->rbytes == node->eol)
			if (!_gnl_getline(&head, node, line, BUFFER_SIZE))
				return ((void *) 0);
		if (node->rbytes == 0)
		{
			_gnl_del_node(&head, node);
			return (line);
		}
		if (node->buff[node->eol] == '\n')
			return (_gnl_makeline(node, node->new_len, &line, IS_END));
		if (node->eol == (size_t)node->rbytes - 1)
			line = _gnl_makeline(node, node->new_len, &line, NOT_END);
		node->eol ++;
		node->new_len ++;
	}
}
