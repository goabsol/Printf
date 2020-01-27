/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:11:48 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/19 23:54:11 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	tens(int n, int *len, int *p)
{
	*p = 1;
	*len = 0;
	while (n / (*p) > 9 || n / (*p) < -9)
	{
		(*p) *= 10;
		(*len)++;
	}
}

char			*ft_itoa(int n)
{
	char			*sn;
	int				s;
	int				len;
	int				p;

	if (n == 0)
		return (ft_strdup("0\0"));
	s = 0;
	tens(n, &len, &p);
	if (!(sn = (char *)malloc((len + 2) * sizeof(char))))
		return (NULL);
	while (p != 0)
	{
		sn[s++] = ((n / p) * ((n / p) > 0 ? 1 : -1) + 48);
		n %= p;
		p /= 10;
	}
	sn[s] = '\0';
	return (sn);
}
