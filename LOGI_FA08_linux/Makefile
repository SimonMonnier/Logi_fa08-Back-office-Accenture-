NAME = Logi_FA08_linux.out

SRC = ./src/*.c

OBJS = *.o

HEADER = ./includes/

FLAGS = -Wall -Wextra -Werror -g 

GCC = gcc

all :
	@make $(NAME)

$(NAME) :
	$(GCC) $(FLAGS) -I$(HEADER) -c $(SRC)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
