NAME	=	demo

CFLAGS	=	-Wall -Wextra -pedantic -ansi
CFLAGS	+=	-I..

OBJ	+=	../CString.o
OBJ	+=	demo.o

RM	=	@rm -f

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean $(NAME)

PHONY	:	all clean fclean re