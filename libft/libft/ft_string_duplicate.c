/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:59:24 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 21:27:14 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	s1_len;

	s1_len = ft_strlen(s1) + 1;
	res = malloc(sizeof(char) * s1_len);
	if (!res)
		return (0);
	ft_memcpy(res, s1, s1_len);
	return (res);
}
