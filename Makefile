NAME = libft.a
COMP = cc 
CFLAGS = -Wall -Wextra -Werror
HDR = hdr/

PERCENT = %

#SRCS

SRC_ARR = $(addprefix src/arr/, \
	  ft_chrarr_int.c \
	  ft_chrarr_len.c \
	  ft_chrarr_long.c \
	  ft_chrarr_ptr.c \
	  ft_freearr.c \
	  ft_freenarr.c \
	  ft_delarr.c \
	  ft_delnarr.c \
	  ft_sortint.c \
	  ft_sortlen.c \
	  ft_sortlong.c \
	  ft_sortptr.c \
	  ft_swapint.c \
	  ft_swaplen.c \
	  ft_swaplong.c \
	  ft_swapptr.c )

SRC_CHAR = $(addprefix src/char/, \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_tolower.c \
	   ft_toupper.c )

SRC_FILE = $(addprefix src/file/, \
	   ft_gnl_tstr.c \
	   ft_gnl.c )

SRC_LST = $(addprefix src/lst/, \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lsttstr_to_tstr.c \
	  ft_lstsize.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstpop.c \
	  ft_lsttstr_to_str.c )

SRC_MATH = $(addprefix src/math/, \
	   ft_max.c \
	   ft_min.c \
	   ft_powi.c )

SRC_MEM = $(addprefix src/mem/, \
	  ft_bspace.c \
	  ft_bzchar.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_memcmp.c )

SRC_PRINT = $(addprefix src/print/, \
	    ft_putchar_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c \
	    ft_putnbrbase_fd.c \
	    ft_putstr_fd.c )

SRC_STR = $(addprefix src/str/, \
	  ft_atoi.c \
	  ft_atoibase.c \
	  ft_in.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_striteri.c \
	  ft_split.c \
	  ft_split_set.c \
	  ft_itoa.c \
	  ft_itoabase.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strmapi.c \
	  ft_strtrim.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_substr.c \
	  ft_strncmp.c )

SRC_TSTR = $(addprefix src/tstr/, \
	   ft_tstr_to_lst.c \
	   ft_iseol.c \
	   ft_tstr_dupstr.c \
	   ft_tstrnew.c \
	   ft_tstrfree.c )

#OBJS

OBJ_ARR = $(SRC_ARR:.c=.o)

OBJ_CHAR = $(SRC_CHAR:.c=.o)

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJ_LST = $(SRC_LST:.c=.o)

OBJ_MATH = $(SRC_MATH:.c=.o)

OBJ_MEM = $(SRC_MEM:.c=.o)

OBJ_PRINT = $(SRC_PRINT:.c=.o)

OBJ_STR = $(SRC_STR:.c=.o)

OBJ_TSTR = $(SRC_TSTR:.c=.o)



#rules

all : $(NAME) arr char file lst math mem print str tstr

good : $(NAME) arr file lst mem str tstr

$(NAME) : 
	@ ar rcs $(NAME) $(HDR)libft.h

%.o: %.c
	@ $(COMP) $(CFLAGS) -c $^ -o $@ -I $(HDR)
	@ ar rcs $(NAME) $^

#folders

arr : $(NAME) mem $(OBJ_ARR)
	@ echo "compiling arr..."

char : $(NAME) $(OBJ_CHAR)
	@ echo "compiling char..."

file : $(NAME) lst $(OBJ_FILE)
	@ echo "compiling file..."

lst : $(NAME) mem $(OBJ_LST)
	@ echo "compiling lst..."

math : $(NAME) $(OBJ_MATH)
	@ echo "compiling math..."

mem : $(NAME) $(OBJ_MEM)
	@ echo "compiling mem..."

print : $(NAME) mem lst $(OBJ_PRINT)
	@ echo "compiling print..."

str : $(NAME) mem lst $(OBJ_STR)
	@ echo "compiling str..."

tstr : $(NAME) mem lst str $(OBJ_TSTR)
	@ echo "compiling tstr..."

#cleaning

clean : 
	@ rm -f $(OBJ_ARR) \
	       	$(OBJ_CHAR) \
	       	$(OBJ_FILE) \
	       	$(OBJ_LST) \
	       	$(OBJ_MATH) \
	       	$(OBJ_MEM) \
	       	$(OBJ_PRINT) \
	       	$(OBJ_STR) \
	       	$(OBJ_TSTR)

fclean : clean
	@ rm -f $(NAME)
	@echo "                                      ,,,,,,,,,                                 \n                                  ,,,..........,,.                              \n                        ,/*. .,,,*,,...........,,**,,...              ***,      \n       .,,           .*#(*,.....,,,,,.....,,,,,,,,..........           ,.       \n      ./#(.         .,......,.,,*****,,,,,,,,,..........,.......                \n     .(#(*         ,,,......,,**/(((///******,,,,...,,,,,......,,.              \n     ($(PERCENT)$(PERCENT)$(PERCENT)#/.   ...,,,,,,,,*****/(###(/*,,,,,,,**,,,,,*****,,,,,,,,...           \n     /$(PERCENT)&&&#/,,........,,,,,,,,,,*//*,.........,,***,,,,,,,,,,,...........       \n      .. .*,,.........,,,.......,,,,...........,,**,.......,,,.........,,,,     \n        .***,,,,....,,**,,,....,,**,,,,,,.,,,,,,****,,,**,,,***,,...,,,,,**.    \n        .*//*********////*******/////**********//((/*//********///******//(/,.  \n         .(((((///(((####((((((######(((((((((((#####((/******//((///((((##/*,. \n          ,($(PERCENT)$(PERCENT)######$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(///////((#######$(PERCENT)$(PERCENT)#///*, \n     .,,**. .,/(#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#((((((((##$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#((///, \n     ,(((/*.     .,/(#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&&&&&&&&&&&&$(PERCENT)&&$(PERCENT)$(PERCENT)#((###$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###((/,  \n      ,/#(/,          .*/(#$(PERCENT)$(PERCENT)##$(PERCENT)$(PERCENT)&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#/,   ,(##########(/.   \n       .*#(*,,.               *(#######((#(####(((##((((*      ,,*/(###/,       \n        .*#$(PERCENT)$(PERCENT)$(PERCENT)#(,             .*#&@@@@@@@@@@@@@@@@@@@&$(PERCENT)/                        \n            *#$(PERCENT)$(PERCENT)#*            . .&&&&&&&@@@@@@@@@@&&#(**...                     \n              ,,.     .**,,,($(PERCENT)$(PERCENT)###(((///(($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)((#(((##$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)##(/*.               \n                  ..,/#$(PERCENT)$(PERCENT)#(#$(PERCENT)&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(((#$(PERCENT)((//(((((((#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(/(*.           \n              ,/((##$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#((#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#######(((((((((((((((###((//(((((*.            \n                *(((#$(PERCENT)$(PERCENT)&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&$(PERCENT)$(PERCENT)###$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)((//((((((((((//(#####(/.             \n                  ,#$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&$(PERCENT)$(PERCENT)########$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(////////////(((((((/               \n                    ,(&&&&&&&$(PERCENT)###########$(PERCENT)&$(PERCENT)#(//////////((((((((/.              \n                    /$(PERCENT)&&&&&&&$(PERCENT)$(PERCENT)#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)####$(PERCENT)$(PERCENT)$(PERCENT)#(/////////((((((((/               \n                 ,($(PERCENT)$(PERCENT)&&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&@@$(PERCENT)//($(PERCENT)$(PERCENT)$(PERCENT)#(((///////(###/((/,               \n               *(##$(PERCENT)$(PERCENT)&&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)##$(PERCENT)@@@@&&&$(PERCENT)$(PERCENT)$(PERCENT)##((((/////($(PERCENT)&@&$(PERCENT)#/.               \n             ,#####$(PERCENT)$(PERCENT)&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)##(#&@@@&&&&$(PERCENT)$(PERCENT)$(PERCENT)##(((((//((#$(PERCENT)&&#(/*               \n            .*#####$(PERCENT)$(PERCENT)&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###((#$(PERCENT)&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###((((((((###(((/,              \n           ,/(###$(PERCENT)$(PERCENT)$(PERCENT)&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###########$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)####((((((((((((((/,             \n         ./(#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###########$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)####(((((((((((((((,            \n            *$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#########$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#########(((((((((*.           \n           ./$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)####$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###(((/////((((/,           \n           *#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(((((((((((((((/,           \n          .($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&&&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)/($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&&&$(PERCENT)######((((((((((((/.  ..       \n          ,($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&&$(PERCENT)#$(PERCENT)$(PERCENT)&&&&&&$(PERCENT)(,/#&&&&&&&&&&$(PERCENT)####$(PERCENT)$(PERCENT)$(PERCENT)####(((#$(PERCENT)$(PERCENT)##/, .*,   ... \n          *($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&$(PERCENT)#*($(PERCENT)&&&&@&$(PERCENT)/**/&&&&&&&&$(PERCENT)$(PERCENT)##$(PERCENT)$(PERCENT)&&&$(PERCENT)#######$(PERCENT)&&&##(/*,.  ,**. \n           ..,#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#/,*#&&&&@&&(/,../($(PERCENT)&&&&$(PERCENT)##$(PERCENT)&&&&$(PERCENT)####(((($(PERCENT)&&&$(PERCENT)(/**/(((/*,  \n              .#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#/*,/#&&&&&&$(PERCENT)#(*,,,*(&&&$(PERCENT)#(#$(PERCENT)&&$(PERCENT)#(((((((((#$(PERCENT)$(PERCENT)((///////*.   \n               *#$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#(/,,...,,,,*($(PERCENT)&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&$(PERCENT)$(PERCENT)#(((((((((((((((((((/////*,      \n                *(/#$(PERCENT)$(PERCENT)#(/*,......,/#&&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)##(((((((((((((((/*,.          \n                    *#&&$(PERCENT)$(PERCENT)#(//(($(PERCENT)&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#########$(PERCENT)$(PERCENT)$(PERCENT)#####(((##(,                \n                     ,($(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)&&$(PERCENT)#(#&&$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)#############$(PERCENT)$(PERCENT)##$(PERCENT)$(PERCENT)#/.                 \n                       .,.  ,#$(PERCENT)$(PERCENT)$(PERCENT)##$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)$(PERCENT)###########$(PERCENT)$(PERCENT)$(PERCENT)#$(PERCENT)#(,                   \n                              .,*.(###$(PERCENT)$(PERCENT)#(/(######$(PERCENT)$(PERCENT)$(PERCENT)//($(PERCENT)#*.                    \n                                    .*###$(PERCENT)$(PERCENT)##((///((#$(PERCENT)$(PERCENT)#(.                      \n                                       ,/####$(PERCENT)$(PERCENT)&&&$(PERCENT)$(PERCENT)#(/.                        \n                                          ,/#$(PERCENT)$(PERCENT)#####,.                          "

re : fclean all

.PHONY: all good fclean clean re arr char file lst math mem print str tstr
