# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekaik-ne <ekaik-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 09:24:24 by ekaik-ne          #+#    #+#              #
#    Updated: 2023/06/28 16:45:56 by ekaik-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c
OBJSDIR = obj
OBJS = $(addprefix $(OBJSDIR)/, $(SRC:%.c=%.o))
.PHONY = all clean fclean re

all: $(NAME)

${NAME}: $(OBJSDIR) $(OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
		mkdir -p $@

$(OBJSDIR)/%.o: src/%.c src/philosophers.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
