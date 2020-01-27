/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:21:24 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/18 22:53:34 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen_fpf(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	if (!(*s) && !c)
		return (0);
	while (1)
	{
		if (s[i] == '\0' && !c--)
			break ;
		i++;
	}
	return (i);
}
