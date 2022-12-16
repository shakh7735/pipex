#SETUP
NAME		=	pipex
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	ft_pipex.h
#HEADER_DIR	=	includes/
#HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))
HEADER		=	$(HEADER_SRCS)

MPATH_SRCS	=	ft_pipex.c
#MPATH_DIR	=	mandatory/
#MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
MPATH		=	$(MPATH_SRCS)
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	ft_pipex_bonus.c mini_gnl.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
#BPATH		=	$(BPATH_SRCS)
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_freeable.c ft_split.c utils.c
#FUNC_DIR	=	functions/
#FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
FUNC 		=	$(FUNC_SRCS)
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

all:			$(NAME)

bonus:			$(OBJ_F) $(OBJ_B) 
				@$(CC) $(OBJ_B) $(OBJ_F) -o $(NAME)
				@echo "$(GREEN)$(NAME) bonus created!$(DEFAULT)"

$(NAME):		$(OBJ_F) $(OBJ_M) 
				@$(CC) $(OBJ_M) $(OBJ_F) -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:			
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_B)
				@$(RM) $(OBJ_F)
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

