/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:16:09 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 21:44:43 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_len;
	size_t	idx;

	s_len = ft_strlen(s);
	res = malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (0);
	idx = 0;
	while (idx < s_len)
	{
		res[idx] = f(idx, s[idx]);
		idx ++;
	}
	res[idx] = 0;
	return (res);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		f(idx, &s[idx]);
		idx ++;
	}
}
