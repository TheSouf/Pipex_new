# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 13:11:40 by sofkhali          #+#    #+#              #
#    Updated: 2025/09/16 10:32:07 by sofkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror 

SRCS = ./src/error.c ./src/free.c ./src/paths.c ./src/pipex.c 

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft/

LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
            ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
            ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
            ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

LIBFT_OBJS = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)
	@echo "✅ Pipex compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  

clean:
	@rm -f $(OBJS) $(LIBFT_OBJS)
	@echo "🧹 Cleaned object files!"

fclean: clean
	@rm -f $(NAME)  
	@echo "🔥 Fully cleaned!"

re: fclean all  

.PHONY: all clean fclean re