# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 10:25:31 by evocatur          #+#    #+#              #
#    Updated: 2023/05/12 16:13:54 by evocatur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out


SRC = $(MAIN_SRC) $(SRC_MAP) $(SRC_GAME) $(GNL_SRC) $(UTILIS_SRC)


MAIN_SRC = *.c

SRC_GAME = game/*.c

SRC_MAP = MapGen/*.c

GNL_SRC = gnl/*.c

UTILIS_SRC = utils/*.c

OBJ = *.o


FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm -rf $(OBJ)
	
$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

play3: all
	@./$(NAME) Map/map_3.ber

play2: all
	@./$(NAME) Map/map_2.ber

play1: all
	@./$(NAME) Map/map_1.ber

play0: all
	@./$(NAME) Map/map_0.ber

norm:
	@echo $(GRAY) ""
	@norminette $(SRC) *.h */*.h
	@echo $(NONE) ""

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all