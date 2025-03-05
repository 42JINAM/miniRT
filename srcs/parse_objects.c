/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:46:27 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 19:35:54 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"
#include <stdio.h>

t_object	*get_last_obj(t_object *obj)
{
	t_object	*curr;

	curr = obj;
	if (curr == NULL)
		return (curr);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

// OBJ_SPHERE
// coordinates
// diameter

// rgb
//
// OBJ_PLANE
// coordinates
// normalized vector 

// rgb
//
//OBJ_CYLINDER
//coordinates
//normalized vector

//diameter
//hegiht
//rgb

int	parse_object_content(int type, const char **tokens, t_object *obj)
{
	obj->id = type;
	obj->next = NULL;
	if (parse_point(tokens[1], &obj->coordinates) != ERR_SUCCESS)
		return (ERR_FILE_NOT_AVAILABLE);
	if (type == OBJ_SPHERE)
	{
		obj->diameter = ft_atof(tokens[2]);
		printf("IN SPHERE : diameter : %f\n", obj->diameter);
	}
	else if (type == OBJ_PLANE || type == OBJ_CYLINDER)
	{
		if (parse_normal_vector(tokens[2], &obj->vector) != ERR_SUCCESS)
			return (ERR_FILE_NOT_AVAILABLE);
	}
	if (type == OBJ_SPHERE || type == OBJ_PLANE)
	{
		if (parse_colors(tokens[3], &obj->rgb) != ERR_SUCCESS)
			return (ERR_FILE_NOT_AVAILABLE);
	}
	else if (type == OBJ_CYLINDER)
	{
		obj->diameter = ft_atof(tokens[3]);
		obj->height = ft_atof(tokens[4]);
		if (parse_colors(tokens[5], &obj->rgb) != ERR_SUCCESS)
			return (ERR_FILE_NOT_AVAILABLE);
	}
	return (ERR_SUCCESS);
}

int	parse_objects(const char **tokens, t_object **obj, int type)
{
	t_object	*object;
	const int	len = ft_array_len(tokens);

	if ((type == OBJ_SPHERE || type == OBJ_PLANE) && (len != 4))
		return (ERR_FILE_NOT_AVAILABLE);
	if (type == OBJ_CYLINDER && len != 6)
		return (ERR_FILE_NOT_AVAILABLE);
	object = ft_calloc(sizeof(t_object), 1);
	if (!object)
		return (ERR_MEMORY_ALLOC);
	if (parse_object_content(type, tokens, object) != ERR_SUCCESS)
		return (ERR_FILE_NOT_AVAILABLE);
	if (*obj == NULL)
		*obj = object;
	else
		get_last_obj(*obj)->next = object;
	return (ERR_SUCCESS);
}
