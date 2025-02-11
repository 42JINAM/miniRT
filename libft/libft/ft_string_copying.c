/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_copying.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:09:50 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 21:04:47 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s2;
	unsigned char	*tmp_s1;

	if (!s1 && !s2)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		tmp_s1[i] = tmp_s2[i];
		i ++;
	}
	return (s1);
}

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (!s1 & !s2)
		return (0);
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	if (s2 < s1)
	{
		i = n;
		while (i > 0)
		{
			tmp_s1[i - 1] = tmp_s2[i - 1];
			i --;
		}
	}
	else if (s2 > s1)
	{
		i = -1;
		while (++i < n)
			tmp_s1[i] = tmp_s2[i];
	}
	return (s1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res_len;

	res_len = ft_strlen(src);
	if (dstsize)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = 0;
	}
	return (res_len);
}
