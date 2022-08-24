/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:00:11 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/24 16:43:00 by buiterma      ########   odam.nl         */
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


typedef struct s_command
{
	char	*path;
	char	*cmnd;
	bool	pipe;
}	t_command;

int			main(void);

//======== Input Validation ========//
bool		validate_read(const char *input_line);

//============ Parsing =============//
t_command	*parse_read(char *input);
t_command	parse_special(char *input);

#endif