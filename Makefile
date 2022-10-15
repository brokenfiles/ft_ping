NAME		= ft_ping
CC			= clang
RM			= rm -f
OBJS_DIR	= ./objects/
HEADERS		= ./includes/
CFLAGS		= -I${HEADERS} -Wall -Wextra -Werror

SRCSC		=	srcs/main.c\
				srcs/parsing/handle_params.c\
				srcs/params/help.c\
				srcs/memory/memory.c\
				srcs/handlers/int_handler.c\
				srcs/utils/utils.c\

OBJS		= ${SRCSC:%.c=${OBJS_DIR}/%.o}

${OBJS_DIR}/%.o: %.c
			@mkdir -p ${@D}
			@printf "\033[2K\033[0;35mFT_PING\033[0;0m:      \033[0;33mCompilation...    \033[0;31m%-15.15s\033[0;0m\r" $(notdir ${<})
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	header ${OBJS}
			@printf "\033[2K\033[0;35mFT_PING\033[0;0m:      \033[0;32mCompleted         \033[0;31m----\033[0;0m          \r\n"
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@printf "\n\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mFT_PING\033[0;0m:      \033[0;32mReady             \033[0;31m----          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

run:		${NAME}
			@echo "\033[0;34mRunning ${NAME}...\033[0;0m"
			@./${NAME}

header:
			@printf "\033[0;0m⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n\033[0;35mNAME          \033[0;0mSTATUS            \033[0;31mFILE          \033[0;0m\n⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤⏤\n"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "\033[0;35mPROJECT\033[0;0m:      \033[0;32mCleaned\033[0;0m\n"

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

silent:
			@:

bonus:		${NAME}

.PHONY:		all clean fclean re bonus rc