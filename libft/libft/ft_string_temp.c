/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:53:25 by jinam             #+#    #+#             */
/*   Updated: 2022/08/12 10:42:00 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	ft_string_init(t_temp_str *temp_str)
{
	temp_str->str = malloc(1024);
	if (!temp_str->str)
		return ;
	temp_str->len = 0;
	temp_str->cap = 1024;
}

void	ft_s_append(t_temp_str *temp_str, char *str)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (temp_str->len == temp_str->cap)
	{
		temp_str->cap *= 2;
		temp = malloc(temp_str->cap);
		if (!temp)
			return ;
		ft_memcpy(temp, temp_str->str, temp_str->len);
		free(temp_str->str);
		temp_str->str = temp;
	}
	while (str[i])
		temp_str->str[(temp_str->len)++] = str[i++];
}

void	ft_c_append(t_temp_str *temp_str, char c)
{
	char	*temp;

	if (temp_str->len == temp_str->cap)
	{
		temp_str->cap *= 2;
		temp = malloc(temp_str->cap);
		if (!temp)
			return ;
		ft_memcpy(temp, temp_str->str, temp_str->len);
		free(temp_str->str);
		temp_str->str = temp;
	}
	temp_str->str[(temp_str->len)++] = c;
}

void	ft_string_clear(t_temp_str *temp_str)
{
	temp_str->len = 0;
}

void	ft_string_delete(t_temp_str *temp_str)
{
	if (!temp_str)
		return ;
	free(temp_str->str);
	temp_str->str = (void *) 0;
}
