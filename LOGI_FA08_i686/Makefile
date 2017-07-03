NAME = Logi_FA08_i686.exe

SRC = ./src/*.c

OBJS = *.o

HEADER = ./includes/

FLAGS = -Wall -Wextra -Werror -g 

GCC = i686-w64-mingw32-gcc

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
