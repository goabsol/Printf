# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arhallab <arhallab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 07:15:18 by arhallab          #+#    #+#              #
#    Updated: 2019/11/19 20:04:18 by arhallab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	chrinstr.c\
			ctoa.c\
			ft_arg_processor.c\
			ft_atoi.c\
			ft_cladd_back.c\
			ft_cldel_back.c\
			ft_clnew.c\
			ft_clclear.c\
			ft_flag_process.c\
			ft_isdigit.c\
			ft_itoa.c\
			ft_printf.c\
			ft_putchar_fd.c\
			ft_putstr_fpf.c\
			ft_strdup.c\
			ft_strlen.c\
			htoa.c\
			htoafpf.c\
			utoa.c

OBJ		=	$(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ) && ranlib $(NAME)
	
$(OBJ) :
	gcc -g -Wall -Werror -Wextra -c $(SRC)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

.Phony : all fclean clean bonus re rebonus