/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:04:22 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 18:08:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_ambient(const char **tokens, t_ambient *ambient)
{
	const int	len = ft_array_len(tokens);
	int			color_parsing_res;

	if (len != 3 || ambient->status == PARSE_AMBIENT)
		return (ERR_FILE_NOT_AVAILABLE);
	ambient->ratio = ft_atof(tokens[1]);
	if (ambient->ratio < 0 || ambient->ratio > 100000)
		return (ERR_FILE_NOT_AVAILABLE);
	color_parsing_res = (parse_colors(tokens[2], &ambient->rgb));
	ambient->status = PARSE_AMBIENT;
	return (color_parsing_res);
}
