/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cladd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:31:05 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/14 22:02:45 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cladd_back(t_cl **alst, t_cl *new)
{
	t_cl *a;

	if (!alst || !new)
		return (0);
	if (!(*alst))
	{
		*alst = new;
		return (1);
	}
	a = *alst;
	while (a->next)
		a = a->next;
	a->next = new;
	return (1);
}
