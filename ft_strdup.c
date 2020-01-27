/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:10:53 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/18 21:21:17 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	size_t	j;

	if (!s)
		return (ft_strdup("(null)\0"));
	j = ft_strlen(s);
	if (!(dup = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_fpf(const char *s, int c)
{
	char	*dup;
	size_t	i;
	size_t	j;

	j = ft_strlen_fpf(s, c);
	if (!(dup = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
