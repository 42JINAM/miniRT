/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:38:48 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 22:07:24 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

static int	_atoi_conv(const char *str, int sign)
{
	int		res;
	size_t	idx;

	res = 0;
	idx = 0;
	while (ft_isdigit(str[idx]))
	{
		res *= 10;
		res += (str[idx] - '0') * sign;
		idx ++;
	}
	return (res);
}

int	ft_atoi(const char *str)
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
	return (_atoi_conv(str + i, sign));
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*tmp;

	total = count * size;
	tmp = malloc(total);
	if (!tmp)
		return (0);
	return (ft_memset(tmp, 0, total));
}
