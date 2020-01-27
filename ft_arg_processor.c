/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:12:20 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/21 02:45:13 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		process(t_cl *cl, char c, va_list args)
{
	int		s;

	s = 0;
	if (c == 's')
		cl->cv = ft_strdup(va_arg(args, char *));
	else if (c == 'c' || c == '%')
		cl->cv = ctoa((c == '%' ? '%' : (char)va_arg(args, int)));
	else if (c == 'd' || c == 'i')
	{
		s = va_arg(args, int);
		cl->sign = (s < 0 ? "-\0" : "\0");
		cl->cv = ft_itoa(s);
	}
	else if (c == 'u')
		cl->cv = utoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		cl->sign = (c == 'p' ? "x0\0" : "\0");
		cl->cv = htoafpf((c == 'p' ? (size_t)va_arg(args, void *) :
		va_arg(args, unsigned int)), c - (c == 'x' ? 'w' : 'X'));
	}
	cl->type = c;
	return ((!cl->cv || !ft_cladd_back(&cl, ft_clnew(NULL)) ? 0 : 1));
}

static int		get_all_flags(t_cl *cl, const char *f, int i, va_list args)
{
	while (!(chrinstr(f[i], "cspdiuxX%\0")))
	{
		if (chrinstr(f[i], "0.-*\0") || ft_isdigit(f[i]))
		{
			i = full_fpross(cl, args, f, i);
			cl->omin_w = cl->min_w;
			i++;
		}
	}
	if (!(process(cl, f[i], args)))
		return (0);
	i++;
	cl->acc = (cl->acc < -1 ? -1 : cl->acc);
	cl->zero *= (chrinstr(cl->type, "diuxXp\0") && cl->acc + 1 ? 0 : 1);
	return (i);
}

static	void	loopforflags(char **na, t_cl **cl)
{
	long	i;

	i = (*cl)->min_w - 1;
	while (i >= 0)
	{
		if ((*cl)->nf)
			(*na)[i--] = ' ';
		else
			(*na)[i--] = ((*cl)->zero ? '0' : ' ');
	}
	i = (long)ft_strlen((*cl)->cv) + ((*cl)->type == 'c' && !*(*cl)->cv);
	while (--i >= 0)
		(*na)[i + ((*cl)->nf ? (long)ft_strlen((*cl)->sign) :
		(*cl)->min_w - ((*cl)->type
		== 'c' && !*(*cl)->cv) - (long)ft_strlen((*cl)->cv))] = (*cl)->cv[i];
	(*na)[(*cl)->min_w++] = '\0';
	while (ft_strlen((*cl)->sign) && !(*cl)->zero && --(*cl)->min_w)
	{
		if (chrinstr((*cl)->type, "ipd\0") && (*cl)->nf && (*(*cl)->cv == ' '
		|| ft_isdigit(*(*cl)->cv)) && (*cl)->min_w - 1 > 2)
			continue ;
		if ((((*na)[(*cl)->min_w] != ' ' && (!(*cl)->nf || (*na)[(*cl)->min_w]
		!= '\0')) || (*cl)->min_w < 3) && (*na)[(*cl)->min_w - 1] == ' ')
			(*na)[(*cl)->min_w - 1] = (*cl)->sign++[0];
	}
}

static int		flagification(t_cl *cl)
{
	char	*na;

	cl->nf = (cl->min_w < 0 ? 1 : cl->nf);
	cl->min_w *= (cl->min_w < 0 ? -1 : 1);
	if (!cl->acc && *cl->cv == '0' && chrinstr(cl->type, "duipxX\0"))
		(forfree(&cl->cv)) && (cl->cv = ft_strdup(""));
	else if (((cl->acc > (long)ft_strlen(cl->cv) || cl->acc == -1)
	&& chrinstr(cl->type, "cs%\0")) || (cl->acc < (long)ft_strlen(cl->cv)
	&& cl->acc != -1 && chrinstr(cl->type, "diuxXp\0")))
		cl->acc = (long)ft_strlen(cl->cv);
	if (!cl->cv || !(chrinstr(cl->type, "c%\0") ? 1 : accarg(&cl)))
		return (0);
	cl->min_w = (cl->min_w < (long)ft_strlen_fpf(cl->cv, (cl->type == 'c'
	&& !(*(cl->cv)))) + (long)ft_strlen(cl->sign) ? (long)ft_strlen_fpf(cl->cv,
	(cl->type == 'c' && !(*(cl->cv)))) + (long)ft_strlen(cl->sign) : cl->min_w);
	if (!(na = (char *)malloc(sizeof(char) * (cl->min_w + 1))))
		return (0);
	loopforflags(&na, &cl);
	if (ft_strlen(cl->sign) && cl->zero)
	{
		na[0] = cl->sign[ft_strlen(cl->sign++) - 1];
		na[1] = (*cl->sign ? cl->sign[ft_strlen(cl->sign) - 1] : na[1]);
	}
	return (freedup(&cl, &na, (cl->type == 'c' && !*cl->cv)));
}

int				find_n_load(t_cl **cl, const char *f, va_list args)
{
	int		j;
	int		i;
	t_cl	*a;

	i = 0;
	a = *cl;
	while (f[i])
	{
		if (f[i] == '%')
		{
			j = get_all_flags(a, f, i + 1, args);
			if (!j || !flagification(a))
				return (0);
			a = a->next;
			a->next = 0x0;
			i = j - 1;
		}
		i++;
	}
	ft_cldel_back(cl);
	return (1);
}
