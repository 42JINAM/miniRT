/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:52:39 by jinam             #+#    #+#             */
/*   Updated: 2022/08/12 16:43:35 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	_printf_x(t_temp_str *t_str, t_format *format, va_list *ap)
{
	unsigned int	nbr;
	char			*base;
	int				res;

	if (format->specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	nbr = va_arg(*ap, unsigned int);
	format->flags &= ~SPACE;
	if ((format->flags & SHARP) == SHARP && nbr != 0)
		res = _pf_base16_process(t_str, format, nbr, (char *)base);
	else if ((format->flags & PRECISION) == PRECISION && \
		format->precision == 0 && nbr == 0)
		res = _nbr_d_zero_precision_zero_process(format, t_str);
	else if ((format->flags & MINUS) == MINUS)
		res = _nbr_d_minus_process(format, t_str, nbr, (char *) base);
	else if ((format->flags & ZERO) == ZERO)
		res = _nbr_d_zero_process(format, t_str, nbr, (char *) base);
	else
		res = _nbr_d_noflag_process(format, t_str, nbr, (char *) base);
	if (res < 0)
		return (-1);
	return (ft_temp_print(t_str, 1));
}

int	_printf_per(t_temp_str *t, t_format *f, va_list *ap)
{
	(void) ap;
	if ((f->flags & MINUS) == MINUS && f->width > 1)
	{
		ft_c_append(t, '%');
		_printf_width(t, f->width - 1, ' ');
	}
	else if (f->width > 1)
	{
		_printf_width(t, f->width - 1, ' ');
		ft_c_append(t, '%');
	}
	else
		ft_c_append(t, '%');
	return (ft_temp_print(t, 1));
}
