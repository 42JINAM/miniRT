/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:27:27 by jinam             #+#    #+#             */
/*   Updated: 2022/11/14 21:15:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

typedef enum e_stat
{
	ERROR = 0,
	SUCCESS,
}	t_stat;

typedef enum e_eof
{
	IS_END = 0,
	NOT_END,
	READ_ERROR
}	t_eof;

typedef struct s_list
{
	int				fd;
	char			buff[BUFFER_SIZE];
	ssize_t			rbytes;
	size_t			eol;
	size_t			last_len;
	size_t			new_len;
	struct s_list	*next;
}					t_list;

int		_gnl_find_node(t_list **head, t_list **node, int fd);
void	_gnl_del_node(t_list **begin_list, t_list *node);

#endif /* ifndef GET_NEXT_LINE_H
# ifndef
 */
