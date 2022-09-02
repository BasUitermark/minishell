/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 12:45:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/02 17:01:42 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

static unsigned int	next_var(char *string, unsigned int from)
{
	while (string[from] && string[from + 1] && \
		!(string[from] == '$' && \
		(ft_isalpha(string[from + 1]) || string[from + 1] == '_')))
		from++;
	if (string[from] != '$')
		from++;
	return (from);
}

static unsigned int	var_length(char *string, unsigned int from)
{
	unsigned int	length;

	length = 1;
	while (string[from + length] && \
		(ft_isalnum(string[from + length]) || string[from + length] == '_'))
		length++;
	return (length);
}

static char	*ft_strndup(char const *str, unsigned int n)
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

static char	*ft_strnappend(char const *s1, char const *s2, unsigned int n)
{
	char	*out;
	t_size	len1;
	t_size	len2;

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

//static char	*

bool	expand(t_env *head, char **location)
{
	
}





int main(int argc, char **argv, char **envp)
{
	//char	*str = ft_strdup("Hello, $USER! Ur in $PWD :)");
	char	*str = ft_strdup(argv[1]);
	t_env	*env;

	env = parse_environment(envp);
	printf("%s\n", str);
	expand(env, &str);
	printf("%s\n", str);
}
