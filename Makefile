SRC				=	philo.c \
					activities.c \
					cave.c \
					utils.c \
					init.c \

SRC_DIR			=	philo
OBJ_DIR			=	obj
HEADER			=	philo.h
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)
NAME			=	philosophers
CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g3
INCLUDES		=	-I./
LDFLAGS			=	-lpthread
VPATH			=	philo \

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJ) $(HEADER)
					$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p obj

run:				all
					./$(NAME)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re
