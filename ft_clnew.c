/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 09:38:43 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/16 02:13:51 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cl	*ft_clnew(void *c)
{
	t_cl	*l;

	if (!(l = (t_cl *)malloc(sizeof(t_cl))))
		return (NULL);
	l->cv = c;
	l->type = 0;
	l->next = NULL;
	l->nf = 0;
	l->zero = 0;
	l->nflags = 0;
	l->acc = -1;
	l->sign = "";
	l->min_w = 0;
	l->omin_w = 0;
	return (l);
}
