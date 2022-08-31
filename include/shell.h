/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:00:11 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 13:26:23 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libs/libft/include/libft.h"

# define SHELL "[mini_pain]> "
# define SPECIAL_CHAR "$|<>\'\""

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_token_type {
	in_file,
	command,
	argument,
	out_file
}	t_token_type;

typedef struct s_token {
	unsigned int	index;
	unsigned int	length;
	t_token_type	type;
	bool			expendable;
	bool			adjecent;
	struct s_token	*next;
}	t_token;

typedef struct s_command {
	char	*path;
	char	**args;
}	t_command;

typedef struct s_shell {
	t_env		*env;
	int			exit_code;
	int			fd_in;
	int			fd_out;
	int			pipe[2];
	pid_t		pid;
	t_command	*cmds;
	size_t		cmd_n;
}	t_shell;

int			main(void);

//======== Input Validation ========//
bool		validate_read(const char *input_line);

//============ Parsing =============//
t_command	*parse_read(char *input);

size_t		command_counter(t_token *tokens);
size_t		arg_counter(t_token *tokens);

t_token		*token_lstnew(unsigned index, unsigned length, t_token_type type);
void		token_lstadd_back(t_token **lst, t_token *new_item);
t_token		*token_lstlast(t_token *lst);
//======== Input Parsing ========//
bool		resolve_paths(t_command *commands);

#endif