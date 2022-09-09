/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:54:44 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:54:45 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_size	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		while (len > 0)
		{
			--len;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
