/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/25 13:38:22 by buiterma      ########   odam.nl         */
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
		return ;
}

void	init_signal(void)
{
	struct termios	t;
	extern int		rl_catch_signals;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
	rl_catch_signals = false;
	signal(SIGQUIT, SIG_IGN);
	set_signals();
}

void	set_signals(void)
{
	struct sigaction	sig;

	sig.sa_handler = &sighandler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}
