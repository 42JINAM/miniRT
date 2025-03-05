/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:33:02 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 18:43:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_enum.h"

int	parse_light(const char **tokens, t_light *light)
{
	const int	len = ft_array_len(tokens);

	if (len != 4 || light->status == PARSE_LIGHT)
		return (ERR_FILE_NOT_AVAILABLE);
	light->status = PARSE_LIGHT;
	if (parse_point(tokens[1], &light->light_point) == ERR_FILE_NOT_AVAILABLE)
		return (ERR_FILE_NOT_AVAILABLE);
	light->brightness = ft_atof(tokens[2]);
	if (light->brightness < 0 || light->brightness > 1)
		return (ERR_FILE_NOT_AVAILABLE);
	return (ERR_SUCCESS);
}
