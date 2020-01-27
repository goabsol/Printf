/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cldel_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:05:20 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/20 12:41:53 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cldel_back(t_cl **cl)
{
	t_cl	*tmp;
	t_cl	*tmp1;

	tmp = *cl;
	tmp1 = *cl;
	while (tmp->next)
	{
		tmp1 = tmp;
		tmp = tmp->next;
	}
	tmp1->next = NULL;
	free(tmp);
	tmp = NULL;
}
