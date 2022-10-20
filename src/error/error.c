/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:30:06 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/20 14:31:35 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	error(char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}
