/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:43 by jinam             #+#    #+#             */
/*   Updated: 2022/07/29 08:09:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_gnl_list	*_gnl_init_node(int fd)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	new->fd = fd;
	new->eol = BUFFER_SIZE;
	new->rbytes = BUFFER_SIZE;
	new->last_len = 0;
	new->new_len = 0;
	new->next = (void *)0;
	return (new);
}

int	_gnl_find_node(t_gnl_list **head, t_gnl_list **node, int fd)
{
	t_gnl_list	*curr;

	if (!*head)
	{
		*head = _gnl_init_node(fd);
		if (!*head)
			return (ERROR);
	}
	curr = *head;
	while (curr && curr->fd != fd)
	{
		if (!curr->next)
		{
			curr->next = _gnl_init_node(fd);
			if (!curr->next)
				return (ERROR);
		}
		curr = curr->next;
	}
	*node = curr;
	return (SUCCESS);
}

void	_gnl_del_node(t_gnl_list **begin_list, t_gnl_list *node)
{
	t_gnl_list	*curr;

	if (!*begin_list)
		return ;
	if (*begin_list == node)
	{
		*begin_list = node->next;
		free(node);
		return ;
	}
	curr = *begin_list;
	while (curr->next)
	{
		if (curr->next == node)
		{
			curr->next = node->next;
			free(node);
			return ;
		}
		curr = curr->next;
	}
	return ;
}
