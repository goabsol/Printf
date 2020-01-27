/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:18:45 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/20 12:27:19 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			forfree(char **ac)
{
	free(*ac);
	*ac = NULL;
	return (1);
}

int			freedup(t_cl **cl, char **ac, int c)
{
	free((*cl)->cv);
	if (!((*cl)->cv = ft_strdup_fpf(*ac, c)))
	{
		free(*ac);
		return (0);
	}
	free(*ac);
	return (1);
}

int			accarg(t_cl **cl)
{
	char	*ac;
	long	t;

	if (!(ac = (char *)malloc(sizeof(char) * ((*cl)->acc + 1))))
		return (0);
	t = (*cl)->acc + 1;
	if ((*cl)->acc >= 0)
		ac[t - 1] = '\0';
	if ((*cl)->acc < (long)ft_strlen((*cl)->cv) &&
	chrinstr((*cl)->type, "cs%\0") && (*cl)->acc != -1)
	{
		while (--t)
			*(ac + (*cl)->acc - t) = *((*cl)->cv + (*cl)->acc - t);
		return (freedup(cl, &ac, 0));
	}
	else if ((*cl)->acc > (long)ft_strlen((*cl)->cv)
	&& chrinstr((*cl)->type, "diuxXp\0"))
	{
		while (--t)
			*(ac + (*cl)->acc - t) =
			(t > (long)ft_strlen((*cl)->cv) ? '0'
			: *((*cl)->cv + (long)ft_strlen((*cl)->cv) - t));
		return (freedup(cl, &ac, 0));
	}
	return (forfree(&ac));
}

int			full_fpross(t_cl *cl, va_list args, const char *f, int i)
{
	cl->nf = (f[i] == '-' || cl->nf ? 1 : 0);
	cl->zero = ((f[i] == '0' || cl->zero) && !(cl->nf) ? 1 : 0);
	cl->nflags += (f[i] == '-' || f[i] == '0' ? 1 : 0);
	if (f[i] == '.')
	{
		cl->acc = 0;
		cl->nflags += (f[i + 1] == '*' ? 2 : 1);
		cl->acc = (long)(f[i + 1] == '*' ? va_arg(args, int)
		: ft_atoi(f + i + 1));
		if (f[i + 1] == '*')
			return (i + 1);
		if (ft_isdigit(f[i + 1]))
		{
			while (ft_isdigit(f[i++ + 1]))
				cl->nflags++;
			return (i - 1);
		}
	}
	if (f[i] == '-' || f[i] == '0' || f[i] == '.')
		return (i);
	cl->min_w = (long)(f[i] == '*' ? va_arg(args, int) : ft_atoi(f + i));
	cl->nflags += (f[i] == '*' ? 1 : 0);
	while (ft_isdigit(f[i++]))
		cl->nflags++;
	return (i - 2 + (f[i - 1] == '*'));
}
