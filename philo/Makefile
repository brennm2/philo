NAME = philo


CC = gcc -g
CCFLAGS = -Wall -Werror -Wextra 
RM = rm
RMFLAGS= -f
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[1;93m
NC=\033[0m

SRC = src/main.c \
	src/utils/arg_utils.c \
	src/utils/free_exit.c \
		



OBJ = $(SRC:.c=.o)
LOCATION = obj/

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
	

	@echo "\n${YELLOW}--------------------------"
	@echo "${YELLOW}| ${GREEN}All files are compiled ${YELLOW}|"
	@echo "${YELLOW}--------------------------${NC}\n"


clean:
	$(RM) $(RMFLAGS) obj/* $(OBJ)

	@echo "\n${YELLOW}-----------------------------"
	@echo "${YELLOW}| ${GREEN}Cleaned all ${RED}program${GREEN} files ${YELLOW}|"
	@echo "${YELLOW}-----------------------------${NC}\n"

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(OBJ)

	@echo "\n${YELLOW}--------------------------------"
	@echo "${YELLOW}| ${RED}ALL files ${GREEN}have been cleaned! ${YELLOW}|"
	@echo "${YELLOW}--------------------------------${NC}\n"

re: fclean all
