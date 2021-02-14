##
## EPITECH PROJECT, 2020
## myprintf
## File description:
## makefile
##

CC				=	gcc
CFLAGS			=	-W -Wall -Wextra
CPPFLAGS		=	-I./include
LDFLAGS			=	-L./ -lmy

SRC				=	$(wildcard src/*.c & wildcard src/redef_signals/*.c)

OBJ				=	$(SRC:.c=.o)

NAME			=	navy

all				:
				$(MAKE) -C lib/my $@
				$(MAKE) gcc

gcc				:	$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LDFLAGS)

lib				:
				$(MAKE) -C lib/my $@

clean			:
				$(RM) $(OBJ)
				$(RM) $(NAME)
				$(RM) src/*~
				$(RM) *~
				$(RM) /#*#/
				$(RM) -rf *.dSYM
				$(MAKE) -C lib/my $@

fclean			:	clean
				$(MAKE) -C lib/my $@

re				:	fclean all
