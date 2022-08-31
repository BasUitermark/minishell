/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:50:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 13:56:07 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

bool	validate_read(const char *input_line)
{
	if (ft_strncmp(input_line, "exit", 4) == 0)
		return (false);
	return (true);
}
