/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   def.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 15:25:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:55:51 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

//=== Libraries ===//
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

//=== Base Strings ===//
# define BINARY "01"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define BUFFER_SIZE 4

//=== Structs ===//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_dlist_i
{
	int					num;
	struct s_dlist_i	*next;
	struct s_dlist_i	*prev;
}	t_dlist_i;

typedef struct s_data_store
{
	char	*readstr;
	char	*r_main;
}t_data_store;

//=== Print Colors ==//

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"
# define LINE		"\x1b[4m"
# define BLINK		"\x1b[5m"
# define CROSS		"\x1b[9m"

#endif