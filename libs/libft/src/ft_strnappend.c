/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnappend.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:09:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:59:16 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnappend(char const *s1, char const *s2, unsigned int n)
{
	char	*out;
	size_t	len1;

	if (!s1)
		return (ft_strndup(s2, n));
	len1 = ft_strlen(s1);
	out = (char *)ft_calloc(len1 + n + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s1, len1);
	ft_memcpy(out + len1, s2, n);
	free((char *)s1);
	return (out);
}
