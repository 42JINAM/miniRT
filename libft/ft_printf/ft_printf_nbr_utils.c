/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggul_jam <ggul_jam@icloud.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:05:09 by ggul_jam          #+#    #+#             */
/*   Updated: 2022/08/24 17:15:28 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	_pf_nbr_pre_process(t_format *format, t_temp_str *t_str, \
								unsigned long n)
{
	if (format->specifier == 'x' || format->specifier == 'X')
	{
		if (n == 0)
			return ;
	}
	if (format->specifier == 'X')
		ft_s_append(t_str, "0X");
	else if (format->specifier == 'x' || format->specifier == 'p')
		ft_s_append(t_str, "0x");
	else
		return ;
}

int	_nbr_noflag_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);
	int			pre;

	if (!conv_n)
		return (-1);
	pre = 0;
	if (format->specifier == 'p' || \
		(format->flags & SHARP) == SHARP)
		pre = 2;
	else
		pre = 0;
	if (format->precision > len)
		_printf_width(t_str, format->width - (format->precision) - pre, ' ');
	else
		_printf_width(t_str, format->width - (len) - pre, ' ');
	_pf_nbr_pre_process(format, t_str, n);
	if ((format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, format->precision - len, '0');
	ft_s_append(t_str, (char *)conv_n);
	free((void *)conv_n);
	return (0);
}

int	_nbr_zero_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);

	if (!conv_n)
		return (-1);
	_pf_nbr_pre_process(format, t_str, n);
	_printf_width(t_str, (format->width - t_str->len - len), '0');
	ft_s_append(t_str, (char *)conv_n);
	free((void *)conv_n);
	return (0);
}

int	_nbr_zero_precision_zero_process(t_format *format, t_temp_str *t_str)
{
	_printf_width(t_str, (format->width), ' ');
	return (0);
}

int	_nbr_minus_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base)
{
	const int	len = _pf_nbr_len(n, ft_strlen(base));
	const char	*conv_n = ft_itoa_base(n, base);

	if (!conv_n)
		return (-1);
	_pf_nbr_pre_process(format, t_str, n);
	if ((format->flags & PRECISION) == PRECISION)
		_printf_width(t_str, (format->precision - len), '0');
	ft_s_append(t_str, (char *) conv_n);
	free((void *)conv_n);
	_printf_width(t_str, (format->width - t_str->len), ' ');
	return (0);
}
