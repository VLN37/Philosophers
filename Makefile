SRC				=	philo.c \
					activities.c \
					cave.c \
					utils.c \
					init.c \
					reaper.c \
					validation.c \

SRCBONUS		=	philo_bonus.c \
					activities_bonus.c \
					cave_bonus.c \
					init_bonus.c \
					reaper_bonus.c \
					utils_bonus.c \
					validation_bonus.c \

SRC_DIR			=	philo
OBJ_DIR			=	obj
HEADER			=	philo.h
HEADERBONUS		=	philo_bonus.h
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)
OBJBONUS		=	$(SRCBONUS:%.c=$(OBJ_DIR)/%.o)
NAME			=	philosophers
NAMEBONUS		=	philosophers_bonus
CC				=	gcc
RM				=	rm -rf
CFLAGS			=
INCLUDES		=	-I./ -I./philo_bonus -I./philo
LDFLAGS			=	-lpthread
VPATH			=	philo philo_bonus \

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:				$(NAME)

bonus:				$(NAMEBONUS)

$(NAME):			$(OBJ_DIR) $(OBJ) $(HEADER)
					$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAMEBONUS):		$(OBJ_DIR) $(OBJBONUS) $(HEADERBONUS)
					$(CC) $(CFLAGS) $(OBJBONUS) $(LDFLAGS) -o $(NAMEBONUS)

$(OBJ_DIR):
					mkdir -p obj

run:				all
					./$(NAME)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAMEBONUS)

re:					fclean all

.PHONY:				all clean fclean re
