/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:54:41 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:54:42 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_min(int *array, int size)
{
	int	i;
	int	min;

	i = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
