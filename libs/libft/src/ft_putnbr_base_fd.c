/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:54:27 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:54:27 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_putnbr_base_fd(size_t n, int fd, char const *base_format)
{
	size_t	out;
	size_t	base;

	base = ft_strlen(base_format);
	out = 0;
	if (n < base)
		out += ft_putchar_fd(base_format[n % base], fd);
	else
	{
		out += ft_putnbr_base_fd(n / base, fd, base_format);
		out += ft_putnbr_base_fd(n % base, fd, base_format);
	}
	return (out);
}
