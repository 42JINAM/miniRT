/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_temp_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:22:09 by jinam             #+#    #+#             */
/*   Updated: 2022/08/12 16:45:34 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_temp_print(t_temp_str *temp_str, int fd)
{
	size_t	res;
	ssize_t	tmp;

	res = 0;
	while (1)
	{
		if (res == temp_str->len)
			return (res);
		tmp = write(fd, &temp_str->str[res], (temp_str->len - res));
		if (tmp == -1)
			return (-1);
		if (tmp == 0)
			return (res);
		res += tmp;
	}
}
