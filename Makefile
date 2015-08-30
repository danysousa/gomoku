export	CC	=	g++
DEBUG		=	TRUE

NAME		=	gomoku

CFLAGS		=	-Wall -Wextra

ifeq ($(DEBUG), FALSE)
	CFLAGS += -Werror
endif

OS			:=	$(shell uname -s)

LIB			:=	`pkg-config --libs --static glfw3`

ifeq ($(OS),Linux)
	LIB += -lGL
endif
ifeq ($(OS),Darwin)
	LIB += -framework OpenGL
endif

INC			=	-I includes `pkg-config --cflags glfw3`

INC_DIR		=	includes/

INC_FILES	=	gomoku.hpp\
				CoreEngine.hpp\
				RenderEngine.hpp\
				IComponent.hpp\
				Goban.hpp\
				Stones.hpp\
				Player.hpp\
				GameEngine.hpp\
				Color.hpp\
				Computer.hpp\

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	main.cpp\
				CoreEngine.cpp\
				RenderEngine.cpp\
				IComponent.cpp\
				Goban.cpp\
				Stones.cpp\
				Player.cpp\
				GameEngine.cpp\
				Color.cpp\
				Computer.cpp\

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

%.o:			%.cpp $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re:				fclean all

.PHONY:			all clean fclean re