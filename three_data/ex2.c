#include <stdio.h>
#include <unistd.h>


// int ft_popen(const char *file, char *const argv[], char type)
// {
// 	int fd[2];
// 	int pid;

// 	if (!file || !argv || (type != 'r' && type != 'w'))
// 		return (-1);
// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (type == 'r')
// 		{
// 			dup2(fd[1], STDOUT_FILENO);
// 			close(fd[1]);
// 		}
// 		else 
// 		{
// 			dup2(fd[0], STDIN_FILENO);
// 			close(fd[0]);
// 		}
// 		close(fd[0]);
// 		close(fd[1]);
// 		execvp(file , argv);
// 		exit(1);
// 	}
// 	if (type == 'r')
// 	{
// 		close(fd[1]);
// 		return (fd[0]);
// 	}
// 	else 
// 	{
// 		close(fd[0]);
// 		return (fd[1]);
// 	}
// }

// 

int    picoshell(char **cmds[])
{
	int fd[2];
	int pid;
	int i;
	int prev_fd;
	int status;
	int exit_code;

	prev_fd = -1;
	exit_code = -1;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd))
			return 1;
		pid = fork();
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if(cmds[i + 1])
		{
			close(fd[0]);
			prev_fd = fd[1];
		}
		i++;
	}
	while (wait(&status))
	{
		if (WIFEXITED(status) && WEXITSTATUS(status))
			exit_code = 1;
	}
	return exit_code;
}


