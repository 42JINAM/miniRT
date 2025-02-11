/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__string_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:04:43 by jinam             #+#    #+#             */
/*   Updated: 2022/11/13 16:57:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	_seplen(char *s, char c);
static int	_split_element(char **res, char const *s, char c);
static char	**_split_free(char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		res_len;

	res_len = _seplen((char *)s, c);
	res = ft_malloc(sizeof(char *) * (res_len + 1));
	if (_split_element(res, s, c) == -1)
	{
		_split_free(res);
		return (0);
	}
	res[res_len] = (void *) 0;
	return (res);
}

static int	_seplen(char *s, char c)
{
	int				len;
	size_t			idx;
	int				flag;
	const size_t	s_len = ft_strlen(s);

	idx = 0;
	flag = 1;
	len = 0;
	while (idx < s_len)
	{
		if (s[idx] != c)
		{
			if (flag == 1)
			{
				flag = 0;
				len ++;
			}
		}
		else
			flag = 1;
		idx ++;
	}
	return (len);
}

static int	_split_element(char **res, char const *s, char c)
{
	size_t	s_idx;
	int		res_idx;
	size_t	sub_len;
	char	*sub_address;

	s_idx = 0;
	res_idx = 0;
	while (s_idx < ft_strlen(s))
	{
		if (s[s_idx] == c)
			s_idx ++;
		else
		{
			sub_address = ft_strchr(&s[s_idx], c);
			if (sub_address)
				sub_len = sub_address - &s[s_idx];
			else
				sub_len = ft_strlen(&s[s_idx]);
			res[res_idx ++] = ft_substr(s, s_idx, sub_len);
			if (!res[res_idx - 1])
				return (-1);
			s_idx += sub_len;
		}
	}
	return (res_idx);
}

static char	**_split_free(char **res)
{
	int	res_idx;

	res_idx = 0;
	while (res[res_idx])
	{
		free(res[res_idx]);
		res_idx ++;
	}
	free(res);
	return (res);
}
