# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 09:24:24 by ekaik-ne          #+#    #+#              #
#    Updated: 2023/07/02 10:59:08 by ekaik-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
SRC = actions.c initialize_values.c ft_atoi.c main.c routine.c utils.c utils_actions.c utils_more.c
OBJSDIR = obj
OBJS = $(addprefix $(OBJSDIR)/, $(SRC:%.c=%.o))
.PHONY = all clean fclean re

all: $(NAME)

${NAME}: $(OBJSDIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@ -pthread

$(OBJSDIR):
		mkdir -p $@

$(OBJSDIR)/%.o: src/%.c src/philosophers.h
		$(CC) $(CFLAGS) -c $< -o $@ -pthread

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
