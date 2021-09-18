NAME		= Cub3D
SHELL       =/bin/bash
define art
${RED}
      ::::::::  :::    ::: :::::::::   ::::::::  :::::::::
    :+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:    :+:
   +:+        +:+    +:+ +:+    +:+        +:+ +:+    +:+
  +#+        +#+    +:+ +#++:++#+      +#++:  +#+    +:+
 +#+        +#+    +#+ +#+    +#+        +#+ +#+    +#+
#+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#    #+#
########   ########  #########   ########  #########

${BLUE} ssandman@student.21-school.ru
${GREEN} cub3D build successful!${RESET}
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

${RED} all objs, libs, executable
 and screenshot has been deleted!

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



SRCS		= ./srcs/assist.c ./srcs/check_args.c ./srcs/dda.c ./srcs/draw.c\
				./srcs/draw_prep.c ./srcs/errors.c ./srcs/get_ids.c \
				./srcs/get_textures.c ./srcs/init.c ./srcs/keys.c \
				./srcs/map_process.c ./srcs/assist2.c ./srcs/movement.c\
				./srcs/parser.c ./srcs/rotate.c ./srcs/spritecast.c \
				./srcs/sprites.c ./srcs/texturer.c ./srcs/main.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f

MLX_FLAGS	= -Lmlx/ -lmlx -lXext -lX11 -lbsd

MATH_FLAGS	= -lm

LIBFT_FLAGS	= -Llibft -lft

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDES	= -I mlx -I libft

HEADER      = ./includes/cub3d.h

all:	${NAME}

$(NAME): ${HEADER} ${OBJS} | libft
		make -C mlx
		${CC} ${OBJS} ${LIBFT_FLAGS} ${MATH_FLAGS} ${MLX_FLAGS} -o ${NAME}
		clear
		@echo "$$art"
libft:
		@make --no-print-directory -C libft

mlx:
		make -C mlx

clean:
		make -C mlx clean
		make -C libft clean
		${RM} ${OBJS}
		clear
		@echo "$$clean"

fclean:	clean
		rm -f libft/libft.a
		rm -f screenshot.bmp
		${RM} ${NAME}
		clear
		@echo "$$fclean"

re:		fclean
	make all

.PHONY : all art clean fclean re libft mlx