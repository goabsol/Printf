/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoafpf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:15:06 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/20 12:03:27 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lenh(size_t n, long *len, size_t *p)
{
	*p = 1;
	*len = 0;
	while (n / *p > 15)
	{
		*p *= 16;
		(*len)++;
	}
}

char		*htoafpf(size_t c, int x)
{
	char	*a;
	int		case_;
	long	len;
	size_t	p;

	lenh(c, &len, &p);
	if (!(a = (char *)malloc((len + 2) * sizeof(char))))
		return (NULL);
	case_ = 65 + 32 * (x ? 1 : 0);
	while (p != 0)
	{
		*a++ = (char)(c / p) + (c / p > 9 ? case_ - 10 : 48);
		c %= p;
		p /= 16;
	}
	*a = '\0';
	return (a - len - 1);
}
