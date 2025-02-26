/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:15:57 by jinam             #+#    #+#             */
/*   Updated: 2025/02/20 21:24:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "../libft/get_next_line/get_next_line_bonus.h"
#include "../libft/libft/libft.h"
#include <fcntl.h>

int	validate_file(const char *rt_file)
{
	const int	file_len = ft_strlen(rt_file);

	return ((file_len > 3) || !ft_strncmp(&rt_file[file_len -3], ".rt", 3));
}

int	open_file(const char *rt_file)
{
	char	*file_name;
	int		fd;

	file_name = ft_strjoin(RTFILES_DIR, rt_file);
	if (!file_name)
		return (ERR_MEMORY_ALLOC);
	fd = open(file_name, O_RDONLY);
	free(file_name);
	return (fd);
}

int	parsing(const char *rt_file, t_scene *scene)
{
	int			fd;
	int			res;
	char		*str;

	if (!validate_file(rt_file))
		return (ERR_FILE_EXTENSION);
	fd = open_file(rt_file);
	if (fd < 0)
		return (ERR_FILE_EXTENSION);
	
	close(fd);
}
