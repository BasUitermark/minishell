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
CFLAGS		= -Wall -Werror -Wextra -Wunreachable-code 
MAKEFLAGS	= --no-print-directory
VALG		= valgrind -s --leak-check=full
RM			= rm -rf
MKDIR		= mkdir -p
HEADERS		= -I include

#===============================================================================: Sourcefiles
SRCS		= $(addprefix src/, $(addsuffix .c, \
				main \
			$(addprefix lexer/, \
				lexer \
				post_processing \
				lexer_utility) \
			$(addprefix parsing/, \
				parser \
				parse_commands \
				parse_adjacent \
				parse_special \
				resolve_paths \
				parse_utility \
				purge_commands) \
			$(addprefix exec/, \
				exec \
				set_shlvl) \
			$(addprefix env/, \
				env \
				expand \
				parse \
				env_utility) \
			$(addprefix builtins/, \
				cmd_cd \
				cmd_echo \
				cmd_env \
				cmd_exit \
				cmd_export \
				cmd_pwd \
				cmd_unset) \
			$(addprefix signals/, \
				signals) \
			$(addprefix utils/, \
				built_in_test) \
			$(addprefix error/, \
				error)))

#===============================================================================: Make commands
all: libft message $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT)/libft.a -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR) objs
	@$(MKDIR) objs/parsing
	@$(MKDIR) objs/lexer
	@$(MKDIR) objs/validation
	@$(MKDIR) objs/env
	@$(MKDIR) objs/builtins
	@$(MKDIR) objs/signals
	@$(MKDIR) objs/utils
	@$(MKDIR) objs/exec
	@$(MKDIR) objs/error
	@$(CC) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
valg: all
	@printf "$(GREEN)Executing $(NAME) with Valgrind\n$(RESET)\n"
	@$(VALG) ./$(NAME)

fsan: CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
fsan: all
	@printf "$(GREEN)Executing $(NAME) with fsanitize\n$(RESET)\n"
	@./$(NAME)

submodules:
	@git submodule update --init --recursive
	@cd libs/libft/ && git pull
	@cd libs/libft/ && git push

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