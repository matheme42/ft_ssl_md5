# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:54:31 by matheme           #+#    #+#              #
#    Updated: 2021/01/07 12:49:31 by matheme          ###   ########lyon.fr    #
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
NAME = ft_ssl

#sources path
SRC_PATH		= srcs

#objects path
OBJ_PATH		= obj

#includes
INC_PATH		= includes
HEADER			= $(INC_PATH)/ft_ssl.h

# sources
NAME_SRC		=	main.c option.c error.c algo.c

# objects
NAME_OBJ		= $(addprefix $(OBJ_PATH)/,$(NAME_SRC:.c=.o))

#compilateur + flags
CC				=	gcc #-g3 -fsanitize=address -g3
CFLAGS			=  -Wall -Wextra -Werror

#librairies
LIBFT			= libft
LIBFT_INC		= libft/includes
LIBFT.A			= $(LIBFT)/libft.a

all : lib $(NAME)

$(NAME) : $(NAME_OBJ) $(LIBFT.A)
	@$(CC) -I $(LIBFT_INC) -L $(LIBFT) $^ -o $@
	@echo "	\033[2K\r$(DARK_BLUE)ft_ssl:		$(GREEN)loaded\033[0m"


$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(LIBFT_INC) -I $(INC_PATH) -c $< -o $@
	@printf "\033[2K\r${G} >>Compiling ${N}$<\033[36m \033[0m"

lib:
	@make -C $(LIBFT)

clean:
	@rm -f $(NAME_OBJ)
	@make -C $(LIBFT) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "	\033[2K\r$(DARK_BLUE)objects:	$(LIGHT_PINK)removing\033[0m"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "	\033[2K\r$(DARK_BLUE)ft_ssl:		$(PINK)removing\033[0m"
	

re: fclean all

nor :
	@printf "\n${B}[NORMINETTE $(NAME)]${N}\n\n"
	@norminette $(SRC_PATH)/*.c $(INC_PATH)/*.h



