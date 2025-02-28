/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:15:57 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 18:09:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"
#include <fcntl.h>

int	parsing_str(char *str, t_scene *scene)
{
	const char	**tokens = (const char **)ft_split(str, ' ');
	const int	type = check_type((char *)tokens[0]);
	int			res;

	if (type == ELEMENT_AMBIENT)
		res = parse_ambient(tokens, &scene->ambient);
	else if (type == ELEMENT_CAMERA)
		res = parse_camera(tokens, &scene->camera);
	else if (type == ELEMENT_LIGHT)
		res = parse_light(tokens, &scene->light);
	else if (type != ELEMENT_UNKNOWN)
		res = parse_objects(tokens, &scene->objs, type);
	else
		res = (ERR_FILE_NOT_AVAILABLE);
	ft_split_free((char **)tokens);
	free(str);
	return (res);
}

int	read_file(int fd, t_scene *scene)
{
	char	*str;
	int		res;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (str[0] == '/' || str[0] == '\n')
		{
			free(str);
			continue ;
		}
		str[ft_strlen(str) - 1] = 0;
		res = parsing_str(str, scene);
		if (res != ERR_SUCCESS)
			return (res);
	}
	return (scene->parsing_state);
}

int	parsing(const char *rt_file, t_scene *scene)
{
	int			fd;
	int			res;

	if (!validate_file(rt_file))
		return (ERR_FILE_EXTENSION);
	fd = open_file(rt_file);
	if (fd < 0)
		return (ERR_FILE_EXTENSION);
	res = read_file(fd, scene);
	/* if res != PARSE_COMPLETE */
	close(fd);
	return (res);
}
