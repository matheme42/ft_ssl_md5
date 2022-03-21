# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matheme <matheme@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 10:38:28 by matheme           #+#    #+#              #
#    Updated: 2022/03/21 11:39:03 by matheme          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[1;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m

# nom de l'executable
NAME = libftprintf.a

#sources path
SRC_PATH		= src/*

#objects path
OBJ_PATH		= obj

#includes
INC_PATH		= include

NAME_SRC		= int.c short.c short_short.c long_long.c long.c option_diouxx.c \
				  ft_atoi.c ft_power.c ft_strchr.c ft_strlen.c ft_strlenc.c \
				  ft_upower.c nbr_len_base.c unbr_len_base.c ft_champs.c \
			 	  option.c option2.c ft_put_double.c ft_putadress.c \
			 	  ft_putchar.c ft_putnbr_in_hexa.c ft_putnbr_in_octo.c \
			 	  ft_putnbr.c ft_putstr.c ft_putstrc.c ft_putnstr.c ft_putunbr.c \
			 	  ft_printf.c

NAME_SRC_LEN	= $(shell echo -n $(NAME_SRC) | wc -w)
I				= 1

# objects
NAME_OBJ		= $(addprefix $(OBJ_PATH)/,$(NAME_SRC:.c=.o))

#compilateur + flags
CC				=	gcc  #-g3 -fsanitize=address -g3
CFLAGS			=  -Wall -Wextra -Werror


all : $(NAME)
	@echo "	\033[2K\r$(DARK_BLUE)ft_printf:\t$(GREEN)loaded\033[0m"

$(NAME) : $(NAME_OBJ)

# compilation du dossier src
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/ft_printf.h
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) -I $(INC_PATH) $(CFLAGS) -c $< -o $@
		@ar rc $(NAME) $@
		$(eval I=$(shell echo $$(($(I)+1))))
		@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"

clean :
	@rm -f $(NAME_OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "\033[2K\r$(DARK_BLUE)objects:\t$(LIGHT_PINK)removing\033[36m \033[0m"

fclean : clean
	@rm -f $(NAME)
	@printf "\033[2K\r$(DARK_BLUE)ft_printf:\t$(PINK)removing\n\033[36m \033[0m"

re : fclean all