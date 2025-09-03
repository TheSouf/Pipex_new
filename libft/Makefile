# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofkhali <sofkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 17:31:36 by sofkhali          #+#    #+#              #
#    Updated: 2025/09/02 13:44:04 by sofkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libft
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar rcs           # Commande pour créer une archive (.a)

SRCS      = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
            ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
            ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
            ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
            ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
            ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
            ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
             ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c

OBJS      = $(SRCS:.c=.o)         # Fichiers objets normaux
BONUS_OBJS = $(BONUS_SRCS:.c=.o)  # Fichiers objets bonus

all: $(NAME)  # Par défaut, compile la librairie sans bonus

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)  # Crée l'archive avec les objets
	@echo "✅ Libft compiled successfully!"

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)  # Ajoute les objets bonus
	@echo "✨ Libft bonus compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  # Compile chaque fichier source

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)  # Supprime les fichiers objets
	@echo "🧹 Cleaned object files!"

fclean: clean
	@rm -f $(NAME)  # Supprime la bibliothèque
	@echo "🔥 Fully cleaned!"

re: fclean all  # Recompile depuis zéro

.PHONY: all bonus clean fclean re  # Empêche les conflits avec des fichiers du même nom