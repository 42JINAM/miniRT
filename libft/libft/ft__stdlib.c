/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__stdlib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:23:57 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 20:36:11 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static size_t	_nbr_len(long nbr)
{
	size_t	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	nbr_len;
	char	*res;

	nbr = (long) n;
	nbr = nbr * ((nbr > 0) - (nbr < 0));
	nbr_len = (n < 0) + _nbr_len(nbr);
	res = malloc(sizeof(char) * (nbr_len + 1));
	if (!res)
		return ((void *) 0);
	res[nbr_len] = 0;
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (nbr)
	{
		res[nbr_len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		nbr_len --;
	}
	return (res);
}
