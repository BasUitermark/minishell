/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/24 17:44:47 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	sighandler(int num)
{
	if (num == SIGINT)
	{	
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (num == SIGQUIT)
	{
		ft_putendl_fd("Quit: 3\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	set_signals(void)
{
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
}

// void	signal_intercept(void)
// {
// 	struct sigaction	sig;

// 	sig.sa_handler = &sighandler;
// 	sigaction(SIGINT, &sig, NULL);
// 	sigaction(SIGQUIT, &sig, NULL);
// }
