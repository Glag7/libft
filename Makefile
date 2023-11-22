NAME = libft.a
COMP = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_CHAR = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c

SRC_LST = ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c

SRC_MEM = ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memcmp.c

SRC_PRINT = ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c

SRC_STR = ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_striteri.c \
	ft_split.c \
	ft_itoa.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_substr.c \
	ft_atoi.c \
	ft_strncmp.c


SRC = $(addprefix src/char/, $(SRC_CHAR)) \
      $(addprefix src/lst/, $(SRC_LST)) \
      $(addprefix src/mem/, $(SRC_MEM)) \
      $(addprefix src/print/, $(SRC_PRINT)) \
      $(addprefix src/str/, $(SRC_STR))

OBJ = $(SRC:.c=.o)

HDR = hdr/libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ) $(HDR)

%.o: %.c
	$(COMP) $(CFLAGS) -c $^ -o $@ -I hdr/

clean : 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re 
