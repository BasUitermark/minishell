#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>

pid_t	g_pid;

bool	ft_fork(pid_t *pid)
{
	pid_t	output;

	output = fork();
	if (output == -1)
		return (false);
	*pid = output;
	return (true);
}

bool	exec_child(int index)
{
	int		fd[2];

	if (!ft_fork(&g_pid))
	{
		printf("Exec Fork Fucked.jpeg\n");
		return (false);
	}
	if (g_pid == 0)
	{
		printf("Executing command: %d\n", index);
		exit (0);
	}
	else
	{
		printf("Parenting...\n");
	}
	return (true);
}

bool	exec_func(size_t index, size_t cmd_n)
{
	bool	ret;
	// int		status;

	printf("Entering exec_func\n");
	while (index < cmd_n - 1)
	{
		printf("Index: 	%d\n", index);
		ret = exec_child(index);
		if (ret == false)
			return (false);
		index++;
	}
	// waitpid(g_pid, &status, 0);
	printf("Executing last command command: %d\n", index);
	return (true);
}

int main(int argc, char const *argv[])
{
	int		status;

	if (!ft_fork(&g_pid))
		printf("First Fork Fucked.jpeg\n");
	if (g_pid == 0 && !exec_func(0, 2))
	{
		printf("Exec be done\n");
	}
	else
		waitpid(g_pid, &status, 0);
	printf("end\n");
	return 0;
}
