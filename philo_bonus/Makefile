SRC				=	philo.c \
					activities.c \
					cave.c \
					utils.c \
					init.c \
					hell.c \
					validation.c \

SRCBONUS		=	philo_bonus.c \
					activities_bonus.c \
					cave_bonus.c \
					init_bonus.c \
					hell_bonus.c \
					utils_bonus.c \
					validation_bonus.c \
					cleanup_bonus.c \
					main_bonus.c \

SRC_DIR			=	philo
OBJ_DIR			=	../obj
BIN_DIR			=	../bin
HEADER			=	philo.h
HEADERBONUS		=	philo_bonus.h
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)
OBJBONUS		=	$(SRCBONUS:%.c=$(OBJ_DIR)/%.o)
NAME			=	../bin/philo
NAMEBONUS		=	../bin/philo_bonus
CC				=	gcc -g3
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	-I./ -I./philo_bonus -I./philo
LDFLAGS			=	-lpthread
VPATH			=	../philo philo_bonus \

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

bonus:				$(NAMEBONUS)

$(NAME):			$(OBJ_DIR) $(OBJ) $(HEADER)
					$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAMEBONUS):		$(OBJ_DIR) $(OBJBONUS) $(HEADERBONUS)
					$(CC) $(CFLAGS) $(OBJBONUS) $(LDFLAGS) -o $(NAMEBONUS)

$(OBJ_DIR):
					mkdir -p ../obj ../bin

run:				all
					./$(NAME)

runbonus:			bonus
					./$(NAMEBONUS)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAMEBONUS) $(BIN_DIR)

re:					fclean all

.PHONY:				all clean fclean re
