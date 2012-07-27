NAME		=	libCString.a

CC		=	gcc
CFLAGS		=	-Wall -Wextra -ansi -pedantic
CFLAGS		+=	-Iinc/

RM		=	@rm -f

SRC		=	src/CString_append.c	\
			src/CString_assign.c	\
			src/CString_c_str.c	\
			src/CString_capacity.c	\
			src/CString_clear.c	\
			src/CString_create.c	\
			src/CString_destroy.c	\
			src/CString_epur.c	\
			src/CString_size.c	\

OBJ		=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ)
			ar rcs $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
