CC = gcc
CFLAGS = -Wall -Wextra -Werror
NASM = nasm
NFLAG = -f macho64
SRCS = ./ft_strlen.s ./ft_strcpy.s ./ft_strcmp.s ./ft_write.s ./ft_read.s ./ft_strdup.s
OBJS = $(SRCS:.s=.o)
NAME = libasm.a
TARGET_NAME = libasm

all : $(NAME)

$(NAME) : $(OBJS)
	ar rsc $@ $^

%.o : %.s
	$(NASM) $(NFLAG) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

test :
	$(CC) $(CFLAGS) main.c -L./ -lasm -o $(TARGET_NAME)

testclean:
	rm -f $(TARGET_NAME)

.PHONY : all clean fclean re test testclean
