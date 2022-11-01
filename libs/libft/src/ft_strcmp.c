/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:33:39 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/01 13:33:41 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[index])
	{
		if (s1[index] != s2[index])
			break ;
		index++;
	}
	return (s1[index] - s2[index]);
}
