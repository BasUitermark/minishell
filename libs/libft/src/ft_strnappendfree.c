/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnappendfree.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:09:35 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/08 17:40:01 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnappendfree(char const *s1, char const *s2, unsigned int n)
{
	char	*out;
	t_size	len1;

	if (!s1)
		return (ft_strndup(s2, n));
	len1 = ft_strlen(s1);
	out = (char *)ft_calloc(len1 + n + 1, sizeof(char));
	if (!out)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_memcpy(out, s1, len1);
	ft_memcpy(out + len1, s2, n);
	free((char *)s1);
	return (out);
}
