/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:45:28 by jinam             #+#    #+#             */
/*   Updated: 2025/02/20 21:24:36 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENUM_H
# define MINIRT_ENUM_H

# define RTFILES_DIR "./rtfiles/"

typedef enum e_error_code
{
	ERR_SUCCESS = 0,
	ERR_INVALID_ARG = -1,
	ERR_FILE_EXTENSION = -2,
	ERR_FILE_NOT_AVAILABLE = -3,
	ERR_MEMORY_ALLOC = -4,
	ERR_MLX_INIT_FAIL = -5,
	ERR_UNKNOWN_ELEMENT = -6,
}	t_error_code;

typedef enum e_element_type
{
	ELEMENT_UNKNOWN = 7,
	ELEMENT_AMBIENT = 8,
	ELEMENT_CAMERA = 9,
	ELEMENT_LIGHT = 10,
	ELEMENT_OBJECT = 11,
}	t_element_type;

typedef enum e_object_type
{
	OBJ_UNKNOWN = 12,
	OBJ_SPHERE = 13,
	OBJ_PLANE = 14,
	OBJ_CYLINDER = 15,
}	t_object_type;

typedef enum e_parse_state
{
	PARSE_START = 16,
	PARSE_AMBIENT = 17,
	PARSE_CAMERA = 18,
	PARSE_LIGHT = 19,
	PARSE_OBJECT = 20,
	PARSE_COMPLETE = 21,
	PARSE_ERROR = 22,
}	t_parse_state;

#endif
