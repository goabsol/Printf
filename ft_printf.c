/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:47:04 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/21 03:17:31 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		unload2(t_cl **tmp, char **nl, size_t *k, size_t *i)
{
	size_t	j;
	size_t	l;
	long	a;
	long	ia;

	j = 0;
	*i += (*tmp)->nflags + 2;
	a = ((*tmp)->nf ? 0 : (*tmp)->omin_w - 1);
	a = (a < 0 ? 0 : a);
	ia = ((*tmp)->type == 'c' && !*((*tmp)->cv + a) ? 1 : 0);
	l = ft_strlen_fpf((*tmp)->cv, ia);
	while (j < l)
		(*nl)[(*k)++] = (*tmp)->cv[j++];
	*tmp = (*tmp)->next;
	return (ia);
}

static size_t	unload(t_cl **cl, const char *f, size_t s)
{
	size_t	i;
	size_t	k;
	size_t	c;
	char	*nl;
	t_cl	*tmp;

	i = 0;
	k = 0;
	c = 0;
	tmp = *cl;
	if (!(nl = (char *)malloc(sizeof(char) * (s + 1))))
		return (0);
	while (f[i])
	{
		c += (f[i] == '%' ? unload2(&tmp, &nl, &k, &i) :
		0 * (nl[k++] = f[i++]));
	}
	nl[k] = '\0';
	ft_putstr_fpf(nl, c);
	free(nl);
	return (k + 1);
}

static size_t	count_conv(const char *f, va_list args)
{
	t_cl	*cl;
	t_cl	*tmp;
	size_t	size;

	if (!(cl = ft_clnew(NULL)))
		return (0);
	if (!(find_n_load(&cl, f, args)))
	{
		ft_clclear(&cl);
		return (0);
	}
	tmp = cl;
	size = ft_strlen(f);
	while (tmp)
	{
		size += ft_strlen_fpf(tmp->cv, (tmp->type == 'c'
		&& !*(tmp->cv))) - tmp->nflags - 2;
		tmp = tmp->next;
	}
	size = unload(&cl, f, size + 1);
	ft_clclear(&cl);
	return (size);
}

int				ft_printf(const char *f, ...)
{
	va_list	args;
	va_list	cargs;

	if (!chrinstr('%', f))
	{
		ft_putstr_fpf((char *)f, 0);
		return (ft_strlen(f));
	}
	va_start(args, f);
	va_copy(cargs, args);
	return (count_conv(f, cargs) - 1);
}
