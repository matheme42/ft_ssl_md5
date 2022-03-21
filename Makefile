# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matheme <matheme@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:54:31 by matheme           #+#    #+#              #
#    Updated: 2022/03/21 11:36:53 by matheme          ###   ########.fr        #
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
INC_PATH		= includes/

# sources
NAME_SRC		=	main.c error.c get_file.c \
					1_md5.c 2_md5_option.c 3_md5_algo.c 4_md5_output.c 5_md5_usage.c\
					1_sha256.c 2_sha256_option.c 3_sha256_algo.c 4_sha256_output.c 5_sha256_usage.c\
					1_whirlpool.c 2_whirlpool_option.c 3_whirlpool_algo.c 4_whirlpool_output.c 5_whirlpool_usage.c\
					1_ft.c 2_ft.c 3_ft.c 4_ft.c 5_ft.c 6_ft.c

NAME_SRC_LEN	= $(shell echo -n $(NAME_SRC) | wc -w)
I				= 1

# objects
NAME_OBJ		= $(addprefix $(OBJ_PATH)/,$(NAME_SRC:.c=.o))

#compilateur + flags
CC				=	gcc  #-g3 -fsanitize=address -g3
CFLAGS			=  -Wall -Wextra -Werror

#librairies
FT_PRINTF			= ft_printf
FT_PRINTF_INC		= ft_printf/
FT_PRINTF.A			= $(FT_PRINTF)/libftprintf.a

all : $(NAME)

$(NAME) : $(FT_PRINTF.A) $(NAME_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "	\033[2K\r$(DARK_BLUE)ft_ssl:\t\t$(GREEN)loaded\033[0m"

# compilation du sous dossier libft
$(OBJ_PATH)/%.o : $(SRC_PATH)/libft/%.c $(INC_PATH)/libft.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH)/ -c $< -o $@
	$(eval I=$(shell echo $$(($(I)+1))))
	@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"

# compilation du sous dossier ssl
$(OBJ_PATH)/%.o : $(SRC_PATH)/ssl/%.c $(INC_PATH)/ft_ssl.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH)/ -I $(FT_PRINTF_INC)/ -c $< -o $@
	$(eval I=$(shell echo $$(($(I)+1))))
	@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"

# compilation du sous dossier md5
$(OBJ_PATH)/%.o : $(SRC_PATH)/md5/%.c $(INC_PATH)/md5.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH)/ -I $(FT_PRINTF_INC)/ -c $< -o $@
	$(eval I=$(shell echo $$(($(I)+1))))
	@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"

# compilation du sous dossier sha256
$(OBJ_PATH)/%.o : $(SRC_PATH)/sha256/%.c $(INC_PATH)/sha256.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH)/ -I $(FT_PRINTF_INC)/ -c $< -o $@
	$(eval I=$(shell echo $$(($(I)+1))))
	@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"

# compilation du sous dossier whirlpool
$(OBJ_PATH)/%.o : $(SRC_PATH)/whirlpool/%.c $(INC_PATH)/whirlpool.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(INC_PATH)/ -I $(FT_PRINTF_INC)/ -c $< -o $@
	$(eval I=$(shell echo $$(($(I)+1))))
	@printf "\033[2K\r${G}$(DARK_BLUE)>>\t\t$(I)/$(shell echo $(NAME_SRC_LEN)) ${N}$(BLUE)$<\033[36m \033[0m"


$(FT_PRINTF.A):
	@make -C $(FT_PRINTF)

clean:
	@rm -f $(NAME_OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "\033[2K\r$(DARK_BLUE)objects:\t$(LIGHT_PINK)removing\033[36m \033[0m"

cleanprintf:
	@make -C $(FT_PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean
	@printf "\033[2K\r$(DARK_BLUE)ft_ssl:\t\t$(PINK)removing\n\033[36m \033[0m"
	

re: fclean all




