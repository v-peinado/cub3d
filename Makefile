#Program name
NAME	= cub3d

#FOLDERS PATH
SRCS_DIR	= ./src/
OBJ_DIR		= ./obj/
INC_DIR		= ./includes/

#SRC FOLDERS PATH

#HEADERS
INC = 	cub3d.h

#SRC

SRCS = main.c utils.c parse.c map.c background.c player.c raycast.c hooks.c

OBJ_FILES   = $(SRCS:.c=.o)
SRC			= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INCLUDES	= $(addprefix $(INC_DIR), $(INC))
OBJ_DIRS	:= $(sort $(dir $(OBJS)))

#LIBft
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

#INC MINILIBX LINUX OR MAC
MLX_DIR = ./minilibx
#MLX_DIR = ./minilibx
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

#COMPILE

GCC = gcc
CFLAGS = #-Wall -Werror -Wextra #-fsanitize=address -g3
MFLAGS = -L ${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd -s
#MFLAGS = -ldl -lmlx -L${MLX_DIR} -framework OpenGL -framework AppKit -lz
LFLAGS:= -L $(LIBFT_DIR) -lft -s
RM = rm -f

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(GCC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(GCC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) $(MFLAGS) 
	@echo  "[FINISHED OK]" 
	
clean:
	@${RM} ${OBJS}
	@${RM} -r ${OBJ_DIR}
	@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} fclean
	@make -C ${MLX_DIR} -f ${MLX_MAKE} clean

fclean: clean
	@${RM} ${OBJS} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re
