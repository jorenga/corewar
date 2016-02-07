CC= gcc
FLAGS= -Wall -Wextra -Werror -g
SRC_ASM = main.c \
		  reader.c \
		  parser.c \
		  error_util.c

SRC_COREWAR=

OBJ_ASM= $(SRC_ASM:.c=.o)
OBJ_COREWAR= $(SRC_OTOOL:.c=.o)

NAME_ASM=asm
NAME_OTOOL=corewar
LIB=-L./libft -lft_core -lft_list -lft_printf
DIR_LFT=./libft
INCLUDES=./libft/includes

.PHONY: clean fclean re all

.SILENT:

all: $(NAME_ASM) $(NAME_OTOOL)

$(NAME_ASM): $(OBJ_ASM)
	(cd $(DIR_LFT) ; make )
	$(CC) -o $(NAME_ASM) $(OBJ_ASM) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_ASM) \033[0mDONE!"

$(NAME_OTOOL): $(OBJ_OTOOL)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME_OTOOL) $(OBJ_OTOOL) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_OTOOL) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	$(CC) -c $(FLAGS) -o $@ $< -I $(INCLUDES)

clean:
	(cd $(DIR_LFT) ; make clean)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	rm -rf $(OBJ_ASM)
	rm -rf $(OBJ_OTOOL)

fclean: clean
	(cd $(DIR_LFT) ; make fclean)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	rm -rf $(NAME_ASM)
	rm -rf $(NAME_OTOOL)

re: fclean all