/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:14:17 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:53:51 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(char const *str, unsigned int n)
{
	char	*out;

	if (!str)
		return (NULL);
	out = (char *)ft_calloc(n + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, str, n);
	out[n] = '\0';
	return (out);
}
