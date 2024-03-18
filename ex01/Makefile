CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp \
			class/Brain.cpp \
			class/Animals/Animal.cpp \
			class/Animals/Dog.cpp \
			class/Animals/Cat.cpp \

OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

OBJ_DIR	=	$(sort $(dir $(OBJ)))

HEADER	=	-I. -Iclass -Iclass/Animals

NAME	=	Polymorphism

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
