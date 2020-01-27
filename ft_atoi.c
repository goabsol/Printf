/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 07:13:31 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/13 18:50:41 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int val;
	int sign;

	sign = 1;
	i = -1;
	val = 0;
	while (s[++i] != '\0')
	{
		if ((s[i] > '/' && s[i] < ':') || s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
				sign = -1;
			if (s[i] == '+' || s[i] == '-')
				i++;
			while (s[i] > '/' && s[i] < ':')
				val = val * 10 + s[i++] - 48;
			return (val * sign);
		}
		else if (s[i] != ' ' && (s[i] < 9 || s[i] > 13))
			return (val * sign);
	}
	return (val * sign);
}
