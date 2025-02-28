/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:06:03 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 18:31:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"

int	parse_orientation(const char *token, t_coordinates *coordinates)
{
	const int	res = parse_point(token, coordinates);

	if (res == ERR_FILE_NOT_AVAILABLE)
		return (res);
	if (coordinates->x < -1 || coordinates->x > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	if (coordinates->y < -1 || coordinates->y > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	if (coordinates->z < -1 || coordinates->z > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	return (ERR_SUCCESS);
}

int	parse_fov(const char *token, t_camera *camera)
{
	camera->fov = ft_atoi(token);
	if (camera->fov <= 0 || camera->fov >= 180)
		return (ERR_FILE_NOT_AVAILABLE);
	return (ERR_SUCCESS);
}

int	parse_camera(const char **tokens, t_camera *camera)
{
	const int	len = ft_array_len(tokens);

	if (camera->status == PARSE_CAMERA)
		return (ERR_FILE_NOT_AVAILABLE);
	camera->status = PARSE_CAMERA;
	if (len != 4)
		return (ERR_FILE_NOT_AVAILABLE);
	if (parse_point(tokens[1], &camera->view_point) \
			== ERR_FILE_NOT_AVAILABLE)
		return (ERR_FILE_NOT_AVAILABLE);
	if (parse_orientation(tokens[2], &camera->orientation) \
			== ERR_FILE_NOT_AVAILABLE)
		return (ERR_FILE_NOT_AVAILABLE);
	return (parse_fov(tokens[3], camera));
}
