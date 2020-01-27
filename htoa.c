/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:15:06 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/18 20:56:42 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	lenh(size_t n, long *len, size_t *p)
{
	*p = 1;
	*len = 0;
	while (n / *p > 15)
	{
		*p *= 16;
		(*len)++;
	}
}

char			*htoa(long c, int x)
{
	long	size;
	long	len;
	char	*a;
	int		case_;
	size_t	p;

	lenh(c, &len, &p);
	size = len + (x ? 0 : 2);
	if (!(a = (char *)malloc((size + 2) * sizeof(char))))
		return (NULL);
	if (!x)
	{
		a[0] = '0';
		a[1] = 'x';
		a += 2;
	}
	case_ = 65 + 32 * (x - 1 > 0 ? 0 : 1);
	while (p != 0)
	{
		*a++ = (char)(c / p) + (c / p > 9 ? case_ - 10 : 48);
		c %= p;
		p /= 16;
	}
	*a = '\0';
	return (a - size - 1);
}
