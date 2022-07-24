# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kessalih <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 09:50:35 by kessalih          #+#    #+#              #
#    Updated: 2022/07/20 09:50:40 by kessalih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFILES = get_next_line.c get_next_line_utils.c draw_map.c check_path.c \
check_map.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c draw_map_second.c
OFILES = $(CFILES:.c=.o)
CC = gcc
RM = rm -rf
AR = ar rcs
FLAGS = -Wall -Werror -Wextra
NAME = solong.a

%.o : %.c
	$(CC) $(FLAGS) $< -c
	$(AR) $(NAME) $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) main.c -lmlx -framework OpenGL -framework AppKit $(NAME) -o solong

all : $(NAME)

clean :
	$(RM) $(OFILES)     

fclean :
	$(RM) $(NAME) $(OFILES) solong

re : fclean all