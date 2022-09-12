#===============================================================================: Filename
NAME		= minishell

#===============================================================================: Source to object conversion location
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#===============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#===============================================================================: Include files
LIBFT		= libs/libft

#===============================================================================: Compile variables
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKEFLAGS	= --no-print-directory
RM			= rm -rf
MKDIR		= mkdir -p
HEADERS		= -I include

#===============================================================================: Sourcefiles
SRCS		= $(addprefix src/, $(addsuffix .c, \
				main \
			$(addprefix lexer/, \
				lexer \
				post_processing \
				utility) \
			$(addprefix parsing/, \
				parser \
				parse_commands \
				parse_adjacent \
				parse_special \
				resolve_paths \
				parse_utility) \
			$(addprefix env/, \
				env \
				expand \
				parse)))

#===============================================================================: Make commands
all: libft message $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT)/libft.a -lreadline -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created!$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR) objs
	@$(MKDIR) objs/parsing
	@$(MKDIR) objs/lexer
	@$(MKDIR) objs/validation
	@$(MKDIR) objs/env
	@$(CC) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
run: all
	@printf "$(GREEN)Executing $(NAME)!\n$(RESET)\n"
	@./$(NAME) $(RUN_ARGS)

#===============================================================================: Build messages
message:
	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

#===============================================================================: Libft Compile
libft:
	@$(MAKE) -C $(LIBFT) $(MAKEFLAGS)

#===============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@$(MAKE) -C $(LIBFT) clean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files and executable
fclean:
	@$(RM) objs/
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run