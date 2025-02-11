/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:40:55 by jinam             #+#    #+#             */
/*   Updated: 2022/11/01 20:16:25 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			specifier;
	int				str_len;
}	t_format;

typedef enum e_flags
{
	PLUS = 1 << 0,
	MINUS = 1 << 1,
	SPACE = 1 << 2,
	SHARP = 1 << 3,
	ZERO = 1 << 4,
	PRECISION = 1 << 5
}	t_flags;

typedef int	(*t_funcptr)(t_temp_str *, t_format *, va_list *);

/*main functions */
int		ft_printf(const char *str, ...);
int		_printf_c(t_temp_str *t, t_format *f, va_list *v);
int		_printf_s(t_temp_str *t, t_format *f, va_list *v);
int		_printf_p(t_temp_str *t, t_format *f, va_list *v);
int		_printf_d(t_temp_str *t, t_format *f, va_list *v);
int		_printf_u(t_temp_str *t, t_format *f, va_list *v);
int		_printf_x(t_temp_str *t, t_format *f, va_list *v);
int		_printf_per(t_temp_str *t, t_format *f, va_list *v);

/* common utils */
void	_printf_width(t_temp_str *t_str, int width, char c);
void	_processing_init(t_format *f, t_temp_str *t_str);
void	_make_sign(t_format *f, t_temp_str *t_str, long n);

/* nbr */
/*p & x*/
int		_pf_base16_process(t_temp_str *t_str, t_format *f, \
					unsigned long n, char *base);
int		_pf_nbr_len(unsigned long nbr, size_t len);
int		_nbr_noflag_process(t_format *f, t_temp_str *t, \
					unsigned long n, char *b);
int		_nbr_zero_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base);
int		_nbr_zero_precision_zero_process(t_format *format, t_temp_str *t_str);
int		_nbr_minus_process(t_format *format, t_temp_str *t_str, \
						unsigned long n, char *base);
/*d and u*/
int		_nbr_d_noflag_process(t_format *f, t_temp_str *t_str, long n, char *b);
int		_nbr_d_zero_process(t_format *f, t_temp_str *t_str, long n, char *b);
int		_nbr_d_minus_process(t_format *f, t_temp_str *t_str, long n, char *b);
int		_nbr_d_zero_precision_zero_process(t_format *f, t_temp_str *t_str);

#endif
