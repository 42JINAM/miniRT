/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:40:56 by jinam             #+#    #+#             */
/*   Updated: 2022/11/04 15:30:31 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int	_isnum(char c)
{
	return (('0' <= c && c <= '9'));
}

static long	_atoi_conv(const char *str, int sign, char *base)
{
	long				res;
	long				conv_chr;
	const size_t		base_len = ft_strlen(base);

	res = 0;
	conv_chr = 1;
	while (*str)
	{
		conv_chr = ft_strchr(base, *str++) - base;
		res *= base_len;
		res += conv_chr * sign;
	}
	return (res);
}

long	ft_atol_base(const char *str, char *base, int *flag)
{
	size_t	i;
	size_t	j;
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
	j = i - 1;
	while (str[++j])
	{
		if (!_isnum(str[j]))
		{
			*flag = -1;
			return (0);
		}
	}
	return (_atoi_conv(str + i, sign, base));
}
