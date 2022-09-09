/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:54:08 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:54:09 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_size	ft_strlcat(char *dst, const char *src, size_t n)
{
	const t_size	dstlen = ft_strlen(dst);
	const t_size	srclen = ft_strlen(src);

	if (dstlen >= n)
		return (srclen + n);
	if (n >= dstlen)
		ft_strlcpy(dst + dstlen, src, n - dstlen);
	return (srclen + dstlen);
}
