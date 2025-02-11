/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_common_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:05:42 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/12 10:55:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	_printf_width(t_temp_str *t_str, int width, char c)
{
	if (width <= 0)
		return ;
	while (width)
	{
		ft_c_append(t_str, c);
		width --;
	}
}

int	_pf_nbr_len(unsigned long nbr, size_t len)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= len;
		i ++;
	}
	return (i);
}

void	_make_sign(t_format *f, t_temp_str *t_str, long n)
{
	if (n < 0)
		ft_c_append(t_str, '-');
	else if ((f->flags & PLUS) == PLUS)
		ft_c_append(t_str, '+');
	else if ((f->flags & SPACE) == SPACE)
		ft_c_append(t_str, ' ');
}

void	_processing_init(t_format *f, t_temp_str *t_str)
{
	ft_string_clear(t_str);
	ft_memset(f, 0, sizeof(t_format));
}
