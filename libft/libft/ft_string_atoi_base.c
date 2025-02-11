/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_atoi_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:40:56 by jinam             #+#    #+#             */
/*   Updated: 2022/08/10 16:09:27 by ggul_jam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int	_atoi_conv(const char *str, int sign, char *base)
{
	int				res;
	int				conv_chr;
	const size_t	base_len = ft_strlen(base);

	res = 0;
	conv_chr = 1;
	while (conv_chr)
	{
		conv_chr = ft_strchr(base, *str++) - base;
		res *= base_len;
		res += conv_chr * sign;
	}
	return (res);
}

int	ft_atoi_base(const char *str, char *base)
{
	size_t	i;
	int		sign;

	i = 0;
	while (_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	return (_atoi_conv(str + i, sign, base));
}
