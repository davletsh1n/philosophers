NAME		= philo
SHELL		=/bin/bash
define art
${GREEN}

           __    _ __                       __
    ____  / /_  (_) /___  _________  ____  / /_  ___  __________
   / __ \/ __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/
  / /_/ / / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  )
 / .___/_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/
/_/                              /_/


${BLUE}                 ssandman's philosophers
${GREEN}                    build successful!${RESET}

endef
export art

define clean
${LIGHTPURPLE}
         ,,
       `7MM
         MM
 ,p6"bo  MM  .gP"Ya   ,6"Yb. `7MMpMMMb.
6M'  OO  MM ,M'   Yb 8)   MM   MM    MM
8M       MM 8M""""""  ,pm9MM   MM    MM
YM.    , MM YM.    , 8M   MM   MM    MM
 YMbmd'.JMML.`Mbmmd' `Moo9^Yo.JMML  JMML.

${RED} all objs has been deleted!
                                         ${RESET}
endef
export clean

define fclean
${BLUE}

    ,...      ,,
  .d' ""    `7MM
  dM`         MM
 mMMmm,p6"bo  MM  .gP"Ya   ,6"Yb. `7MMpMMMb.
  MM 6M'  OO  MM ,M'   Yb 8)   MM   MM    MM
  MM 8M       MM 8M""""""  ,pm9MM   MM    MM
  MM YM.    , MM YM.    , 8M   MM   MM    MM
.JMML.YMbmd'.JMML.`Mbmmd' `Moo9^Yo.JMML  JMML.

${RED} all objs, executable

                                         ${RESET}
endef
export fclean

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

ifndef NOPRINT
MAKEFLAGS += --no-print-directory
endif

SRCS		= assist.c\
				cycle.c\
				get_args.c\
				init.c\
				philo.c\


OBJS		= ${SRCS:.c=.o}

CC			= @gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

HEADER		= ./philo.h

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${HEADER} ${OBJS}
		${CC} ${OBJS} -pthread -o ${NAME}
		@clear
		@echo "$$art"

all:	${NAME}

clean:
		${RM} ${OBJS}
		@clear
		@echo "$$clean"

fclean:	clean
		${RM} ${NAME}
		clear
		@echo "$$fclean"

re:		fclean
		make all

.PHONY : all art clean fclean re
