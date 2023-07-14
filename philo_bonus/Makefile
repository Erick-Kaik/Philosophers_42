# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 16:19:52 by ekaik-ne          #+#    #+#              #
#    Updated: 2023/07/14 16:21:34 by ekaik-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = philo_bonus
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
SRC = actions.c  ft_atoi.c  initialize_values.c  main.c  routine.c  utils.c
OBJSDIR = obj
OBJS = $(addprefix $(OBJSDIR)/, $(SRC:%.c=%.o))
.PHONY = all clean fclean re

all: $(NAME)

${NAME}: $(OBJSDIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@ -pthread

$(OBJSDIR):
		mkdir -p $@

$(OBJSDIR)/%.o: src_bonus/%.c src_bonus/philosophers_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@ -pthread

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
