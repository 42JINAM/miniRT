/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:54:50 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 19:25:58 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"

int	valide_color(int color)
{
	return (color >= 0 && color <= 255);
}

int	parse_colors(const char *str, t_colors *color)
{
	const char	**tokens = (const char **)ft_split(str, ',');

	if (ft_array_len(tokens) != 3)
	{
		ft_split_free((char **)tokens);
		return (ERR_FILE_NOT_AVAILABLE);
	}
	color->r = ft_atoi(tokens[0]);
	color->g = ft_atoi(tokens[1]);
	color->b = ft_atoi(tokens[2]);
	ft_split_free((char **)tokens);
	if (!valide_color(color->r))
		return (ERR_FILE_NOT_AVAILABLE);
	if (!valide_color(color->g))
		return (ERR_FILE_NOT_AVAILABLE);
	if (!valide_color(color->b))
		return (ERR_FILE_NOT_AVAILABLE);
	return (ERR_SUCCESS);
}

int	parse_point(const char *str, t_coordinates *loc)
{
	const char	**tokens = (const char **)ft_split(str, ',');
	const int	len = ft_array_len(tokens);

	if (len != 3)
	{
		ft_split_free((char **)tokens);
		return (ERR_FILE_NOT_AVAILABLE);
	}
	loc->x = ft_atof(tokens[0]);
	loc->y = ft_atof(tokens[1]);
	loc->z = ft_atof(tokens[2]);
	ft_split_free((char **)tokens);
	return (ERR_SUCCESS);
}

int	check_type(const char *str)

{
	if (!str)
		return (ELEMENT_UNKNOWN);
	else if (str[0] == 'A')
		return (ELEMENT_AMBIENT);
	else if (str[0] == 'C')
		return (ELEMENT_CAMERA);
	else if (str[0] == 'L')
		return (ELEMENT_LIGHT);
	else if (ft_strncmp(str, "sp", 3) == 0)
		return (OBJ_SPHERE);
	else if (ft_strncmp(str, "pl", 3) == 0)
		return (OBJ_PLANE);
	else if (ft_strncmp(str, "cy", 3) == 0)
		return (OBJ_CYLINDER);
	else
		return (ELEMENT_UNKNOWN);
}

int	parse_normal_vector(const char *str, t_coordinates *vec)
{
	const int	res = parse_point(str, vec);

	if (vec->x < -1 || vec->x > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	if (vec->y < -1 || vec->y > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	if (vec->z < -1 || vec->z > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	return (ERR_SUCCESS);
}
