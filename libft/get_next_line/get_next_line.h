/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:27:27 by jinam             #+#    #+#             */
/*   Updated: 2022/07/28 14:20:09 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);

typedef enum e_eof
{
	IS_END = 0,
	NOT_END,
	READ_ERROR
}	t_eof;

typedef struct s_list
{
	char			buff[BUFFER_SIZE];
	ssize_t			rbytes;
	size_t			eol;
	size_t			last_len;
	size_t			new_len;
}					t_list;
#endif /* ifndef GET_NEXT_LINE_H
# ifndef
 */
