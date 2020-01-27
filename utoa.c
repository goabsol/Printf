/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:36:18 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/19 23:54:07 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			utens(unsigned int n, unsigned int *len, unsigned int *p)
{
	*p = 1;
	*len = 0;
	while (n / (*p) > 9)
	{
		*p *= 10;
		(*len)++;
	}
}

char				*utoa(unsigned int n)
{
	char			*sn;
	unsigned int	s;
	unsigned int	len;
	unsigned int	p;

	s = 0;
	if (n == 0)
		return (ft_strdup("0\0"));
	utens(n, &len, &p);
	if (!(sn = (char *)malloc((len + 2) * sizeof(char))))
		return (NULL);
	while (p != 0)
	{
		sn[s++] = n / p + 48;
		n %= p;
		p /= 10;
	}
	sn[s] = '\0';
	return (sn);
}
