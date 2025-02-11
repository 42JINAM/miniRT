/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:32:56 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/11 22:09:17 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_temp_copy_str(t_temp_str *t_str, char *str, int len)
{
	while (len)
	{
		ft_c_append(t_str, *str);
		str ++;
		len --;
	}
}

static void	_printf_s_fill_str(t_temp_str *t_str, t_format *format,
							char *str, int str_len)
{
	const int	width = format->str_len - str_len;

	if ((format->flags & MINUS) == MINUS)
	{
		_temp_copy_str(t_str, str, str_len);
		_printf_width(t_str, width, ' ');
	}
	else
	{
		_printf_width(t_str, width, ' ');
		_temp_copy_str(t_str, str, str_len);
	}
}

static int	_printf_s_make_str(t_format *format, char *str,
							t_temp_str *t_str)
{
	const int	str_len = ft_strlen(str);

	if (!format->precision && (format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, format->width, ' ');
	else if (!((format->flags & PRECISION) == PRECISION))
		_printf_s_fill_str(t_str, format, str, str_len);
	else
	{
		if (format->precision >= str_len)
			_printf_s_fill_str(t_str, format, str, str_len);
		else
			_printf_s_fill_str(t_str, format, str, format->precision);
	}
	return (ft_temp_print(t_str, 1));
}

int	_printf_s(t_temp_str *t_str, t_format *format, va_list *ap)
{
	char	*str;
	int		str_len;
	int		len;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if ((format->flags & PRECISION) && format->precision < str_len)
		len = format->precision;
	else
		len = str_len;
	format->str_len = len * (len > format->width) + \
		format->width * (format->width >= len);
	return (_printf_s_make_str(format, str, t_str));
}
