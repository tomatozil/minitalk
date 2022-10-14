# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 16:16:23 by jiyun             #+#    #+#              #
#    Updated: 2022/10/14 16:16:38 by jiyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF = ftprintf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = -L./ft_printf -lftprintf

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

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(FT_PRINTF_LIB) -o $(SERVER) $(OBJ_S)
$(CLIENT): $(OBJ_C) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(FT_PRINTF_LIB) -o $(CLIENT) $(OBJ_C)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_S_BONUS) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(FT_PRINTF_LIB) -o $(SERVER_BONUS) $(OBJ_S_BONUS)
$(CLIENT_BONUS): $(OBJ_C_BONUS) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(FT_PRINTF_LIB) -o $(CLIENT_BONUS) $(OBJ_C_BONUS)

$(FT_PRINTF_LIB):
		make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ_S) $(OBJ_C)
	rm -f $(OBJ_S_BONUS) $(OBJ_C_BONUS)
	rm -f $(FT_PRINTF_DIR)/lib$(FT_PRINTF).a
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
