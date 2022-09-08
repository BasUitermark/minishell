/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freearray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:50:56 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/08 15:59:44 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_freearray(char **arr)
{
	int	index;

	index = 0;
	while (arr && arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
	return (NULL);
}
