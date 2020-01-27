/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrinstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:18:48 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/13 09:39:01 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		chrinstr(char c, const char *s)
{
	int i;

	i = 0;
	while (s[i])
		if (c == s[i++])
			return (1);
	return (0);
}