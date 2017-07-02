NAME = Logi_FA08_X86_64.exe

SRC = ./src/*.c

OBJS = *.o

HEADER = ./includes/

FLAGS = -Wall -Wextra -Werror -g 

GCC = x86_64-w64-mingw32-gcc

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
