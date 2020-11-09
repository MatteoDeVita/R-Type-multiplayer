##
## EPITECH PROJECT, 2020
## B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
## File description:
## Makefile
##

CXX     =       g++

CXXFLAGS        =		-I ../src/server/include \
						-I ../src/gameEngine/gameEngine_ns/include \
						-I ../src/gameEngine/geometry_ns/include \
						-I ../src/gameEngine/object_ns/include \
						-I ../src/gameEngine/window_ns/include \
						-I ../src/gameEngine/event_ns/include \
						-I ../src/gameEngine/action_ns/include \
						-I ../src/gameEngine/audio_ns/include \
    					-I ../src/gameObjects/include \
						-I ../src/client/include \
						-I ../src/utils/error/include \
						-I ../src/utils/models \
						-fPIC \
						-g \
						-g3 \
						-Wall \
						-Wextra \
						-lboost_date_time \
						-lsfml-graphics \
						-lsfml-window \
						-lsfml-system \
						-lsfml-audio \
						-lboost_serialization \
						-lboost_system \
						-lboost_thread \
						-lpthread \
						--coverage \
						-lcriterion \
						-Wall \
						-Wextra

EXEC    =       unit_tests

SRC     =       $(wildcard *.cpp) \
				$(wildcard ../src/gameEngine/*/src/*.cpp) \
				$(wildcard ../src/utils/*/src/*.cpp)

OBJ     =       $(SRC:.cpp=.o)				

TEST_OBJ	=	$(SRC:.cpp=.gcno) \
				$(SRC:.cpp=gcda)

END         =   \033[0m
BOLD        =   \033[1m
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
BLINK       =   \033[32;5m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PURPLE      =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m

all: $(EXEC)

start:
	@echo "$(BOLD)$(CYAN)\n\n\t-----STARTING COMPILATION-----\n\n$(YELLOW)"

$(EXEC): start $(OBJ)
	@$(CXX) $(SRC) $(CXXFLAGS) -o $(EXEC)
	@echo "$(BOLD)$(GREEN)\n\n\t-----COMPILATION SUCCESSFUL-----$(END)"

tests_run: $(EXEC)
	./${EXEC}

clean:
	@rm -rf $(OBJ) $(TEST_OBJ) *.gcda *.gcno
	@echo "$(BOLD)$(GREEN)\t-----WORKSPACE CLEANED-----$(END)"

fclean: clean
	@rm -rf $(EXEC)
	@echo "$(BOLD)$(GREEN)\t-----WORKSPACE FCLEANED-----$(END)"

re: fclean all

.PHONY: clean fclean all re