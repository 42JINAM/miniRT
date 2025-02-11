/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:28:52 by jinam             #+#    #+#             */
/*   Updated: 2022/11/13 16:57:29 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*res;

	s_len = ft_strlen(s);
	if (s_len <= start)
		sub_len = 1;
	else if (ft_strlen(s + start) <= len)
		sub_len = ft_strlen(s + start) + 1;
	else
		sub_len = len + 1;
	res = ft_malloc(sizeof(char) * (sub_len));
	ft_strlcpy(res, s + start, sub_len);
	return (res);
}

char	*ft_strtrim(char const	*s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strchr(set, s1[end]) && start < end)
		end --;
	return (ft_substr(s1, start, end - start + 1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = ft_malloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_memcpy(res, s1, ft_strlen(s1) + 1);
	ft_memcpy(res + s1_len, s2, s2_len + 1);
	return (res);
}
