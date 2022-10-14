# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 16:16:23 by jiyun             #+#    #+#              #
#    Updated: 2022/10/14 18:03:33 by jiyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_FLAG = -L./ft_printf -lftprintf
FT_PRINTF_LIB = libftprintf.a

#mandatory
SERVER = server
CLIENT = client
SRC_S = server.c
SRC_C = client.c
OBJ_S = server.o
OBJ_C = client.o

#bonus
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRC_S_BONUS = server_bonus.c
SRC_C_BONUS = client_bonus.c
OBJ_S_BONUS = server_bonus.o
OBJ_C_BONUS = client_bonus.o

INCLUDES = -I./ -I $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(FT_PRINTF_LIB) $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S)
		$(CC) $(CFLAGS) $(FT_PRINTF_FLAG) -o $(SERVER) $(OBJ_S)
$(CLIENT): $(OBJ_C)
		$(CC) $(CFLAGS) $(FT_PRINTF_FLAG) -o $(CLIENT) $(OBJ_C)

bonus: $(FT_PRINTF_LIB) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_S_BONUS)
		$(CC) $(CFLAGS) $(FT_PRINTF_FLAG) -o $(SERVER_BONUS) $(OBJ_S_BONUS)
$(CLIENT_BONUS): $(OBJ_C_BONUS)
		$(CC) $(CFLAGS) $(FT_PRINTF_FLAG) -o $(CLIENT_BONUS) $(OBJ_C_BONUS)

$(FT_PRINTF_LIB):
		make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ_S) $(OBJ_C)
	rm -f $(OBJ_S_BONUS) $(OBJ_C_BONUS)
	rm -f $(FT_PRINTF_DIR)/$(FT_PRINTF_LIB)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
