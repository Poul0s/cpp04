CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

SRC		=	class/AMateria.cpp			\
			class/Character.cpp			\
			class/Ice.cpp				\
			class/Cure.cpp				\
			class/MateriaSource.cpp		\
			main.cpp					\

OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

OBJ_DIR	=	$(sort $(dir $(OBJ)))

HEADER	=	-Iclass -I.

NAME	=	ex03

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADER) $^ -o $@ -c

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
