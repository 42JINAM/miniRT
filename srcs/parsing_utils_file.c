/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:29:33 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 17:55:22 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"
#include "miniRT_enum.h"
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
