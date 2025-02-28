/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:24:09 by jinam             #+#    #+#             */
/*   Updated: 2025/02/28 16:41:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

int	_is_valid_number(const char *str)
{
	int	index;
	int	has_dot;

	index = 0;
	has_dot = 0;
	if (str[index] == '+' || str[index] == '-')
		index ++;
	while (str[index])
	{
		if (str[index] == '.')
		{
			if (has_dot == 1)
				return (0);
			has_dot = 1;
			index ++;
		}
		if ('0' > str[index] || str[index] > '9')
			return (0);
		index ++;
	}
	return (1);
}

int	ft_atof(const char *str)
{
	float		whole_n;
	float		decimal_n;
	int			digit_index;
	const char	*decimal_pos = ft_strchr(str, '.');

	if (!str || ! _is_valid_number(str))
		return (NAN);
	whole_n = ft_atoi(str);
	decimal_n = 0;
	if (!decimal_pos)
		return (whole_n);
	digit_index = ft_strlen(decimal_pos + 1);
	while (digit_index)
	{
		decimal_n += decimal_pos[digit_index] - '0';
		decimal_n *= 0.1;
		digit_index--;
	}
	if (str[0] == '-')
		whole_n -= decimal_n;
	else
		whole_n += decimal_n;
	return (whole_n);
}
