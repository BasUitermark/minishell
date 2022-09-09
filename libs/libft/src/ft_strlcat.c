/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:54:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:59:16 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);

	if (dstlen >= n)
		return (srclen + n);
	if (n >= dstlen)
		ft_strlcpy(dst + dstlen, src, n - dstlen);
	return (srclen + dstlen);
}
