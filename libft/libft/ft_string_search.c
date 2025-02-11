/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:54:49 by jinam             #+#    #+#             */
/*   Updated: 2022/07/20 09:33:08 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s = (unsigned char *)s;
	const unsigned char	tmp_c = (unsigned char)c;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return ((void *) &tmp_s[i]);
		i++;
	}
	return ((void *) 0);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == (unsigned char) c)
			return ((char *) tmp_s);
		tmp_s++;
	}
	if (c == 0)
		return ((char *) tmp_s);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp_s;
	char			*res;

	tmp_s = (unsigned char *)s;
	res = 0;
	while (*tmp_s)
	{
		if (*tmp_s == (unsigned char) c)
			res = (char *) tmp_s;
		tmp_s++;
	}
	if (c == 0)
		return ((char *) tmp_s);
	return (res);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_len;

	idx = 0;
	needle_len = ft_strlen(needle);
	if (! needle_len)
		return ((char *) haystack);
	while (haystack[idx] && idx + needle_len <= len)
	{
		if (ft_strncmp(&haystack[idx], needle, needle_len) == 0)
			return ((char *) &haystack[idx]);
		idx ++;
	}
	return (0);
}
