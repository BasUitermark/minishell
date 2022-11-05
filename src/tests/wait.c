#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


void	exec_func(void)
{
	pid_t	pid;

	pid = fork(); //fork commands
}

int main(int argc, char const *argv[])
{
	pid_t	pid;
	int		status;

	pid = fork(); // fork from main loop
	if (pid == 0)
		exec_func();
	else
	{
		waitpid(pid, &status, 0);
		printf("parent\n");
	}
	printf("end\n");
	return 0;
}
