/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:20:18 by arhallab          #+#    #+#             */
/*   Updated: 2019/11/19 20:03:42 by arhallab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_cl
{
	long		min_w;
	long		omin_w;
	long		acc;
	long		zero;
	long		nf;
	long		nflags;
	char		*cv;
	char		*sign;
	char		type;
	struct s_cl *next;
}				t_cl;
int				ft_printf(const char *frm, ...);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_fpf(const char *s, int c);
char			*htoafpf(size_t c, int x);
char			*htoa(long c, int x);
char			*ctoa(char c);
char			*utoa(unsigned int n);
char			*ft_itoa(int n);
void			ft_putstr_fpf(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
t_cl			*ft_clnew(void *c);
int				ft_cladd_back(t_cl **alst, t_cl *new);
void			ft_cldel_back(t_cl **cl);
int				find_n_load(t_cl **cl, const char *f, va_list args);
int				ft_atoi(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				chrinstr(char c, const char *s);
int				full_fpross(t_cl *cl, va_list args, const char *f, int i);
int				ft_isdigit(int c);
int				accarg(t_cl **cl);
int				freedup(t_cl **cl, char **ac, int c);
char			*ft_strdup(const char *s);
char			*ft_strdup_fpf(const char *s, int c);
void			ft_clclear(t_cl **lst);
int				forfree(char **ac);
#endif
