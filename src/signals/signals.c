/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/13 21:46:52 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sig_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler_exec(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_shell.exit_code = 130;
	}
	if (sig == SIGQUIT)
	{
		write(1, "Quit: 3\n", 8);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_shell.exit_code = 131;
	}
}

static void	sighandler(int num)
{
	if (num == SIGINT)
	{	
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_signal(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
}

