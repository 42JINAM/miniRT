/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:18:34 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/12 16:45:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_pf_base16_process(t_temp_str *t_str, t_format *f,
						unsigned long n, char *base)
{
	if ((f ->flags & PRECISION) == PRECISION && f -> precision == 0 && n == 0)
		return (_nbr_zero_precision_zero_process(f, t_str));
	else if ((f ->flags & MINUS) == MINUS)
		return (_nbr_minus_process(f, t_str, n, base));
	else if ((f->flags & ZERO) == ZERO)
		return (_nbr_zero_process(f, t_str, n, base));
	else
		return (_nbr_noflag_process(f, t_str, n, base));
}

int	_printf_p(t_temp_str *t_str, t_format *format, va_list *ap)
{
	unsigned long	pointer;

	pointer = (unsigned long) va_arg(*ap, void *);
	if (!(t_str->str) || \
		_pf_base16_process(t_str, format, pointer, "0123456789abcdef") < 0)
		return (-1);
	return (ft_temp_print(t_str, 1));
}
