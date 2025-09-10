#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

// test 1 
// int main()
// {
// 	int fd[2];
// 	char buffer[21];
// 	// 0 : read
// 	// 1 : write  
// 	if (pipe(fd) == -1)
// 	{
// 		printf("error in pipe");
// 		return (1);
// 	}
// 	write(fd[1], "test ayoub ouahidi \n", 21);
// 	read(fd[0], buffer, 21);
// 	printf("output in buffer is ==> %s\n", buffer);
// 	close(0);
// 	close(1);
// }

// int main()
// {
// 	int	fd[2];
// 	char buffer[22];
	
// 	pipe(fd);
// 	write(fd[1], "test ayoub ouahidi \n", 21);
// 	read(fd[0], buffer, 21);
	

// }
// test 2
// int main()
// {
	// int fd[2];
	// char buffer[27];
	// pid_t pid;
// 
	// if (pipe(fd) == -1)
	// {
		// printf("pipe erro !");
		// return 1;
	// }
	// pid = fork();
	// if (pid == 0)
	// {
		// close(fd[0]);
		// write(fd[1], "ouahidi ayoub test child \n", 27);
		// close(fd[1]);
	// }
	// else if (pid != 0)
	// {
		// close(fd[1]);
		// read(fd[0], buffer, 27);
		// close(fd[0]);
		// printf("received from child %s\n", buffer);
	// }
// }
// 
// 

// int	ft_popen(const char *file, char *const argv[], char type)
// {
// 	int	fds[2];
// 	pid_t pid;

// 	if (!file || !argv || (type != 'r' && type != 'w'))
// 		return (-1);
// 	if (pipe(fds) == -1)
// 		return (-1);
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		close(fds[0]);
// 		close(fds[1]);
// 		return (-1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (type == 'r')
// 		{
// 			if (dup2(fds[1], STDOUT_FILENO) == -1)
// 				exit(1);
// 		}
// 		else
// 		{
// 			if (dup2(fds[0], STDIN_FILENO) == -1)
// 				exit(1);
// 		}
// 		close(fds[0]);
// 		close(fds[1]);
// 		execvp(file, argv);
// 		exit(1);
// 	}
// 	if (type == 'r')
// 	{
// 		close(fds[1]);
// 		return fds[0];
// 	}
// 	else
// 	{
// 		close(fds[0]);
// 		return fds[1];
// 	}
// }
// int main()
// {
// 	int fd[2];
// 	char* args[] = {"ls", "-ls", NULL};
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (execvp(args[0], args)){
// 			printf("error in exec");
// 			return (1);
// 		}
// 	}
// 	else 
// 	{
// 		wait(NULL);
// 		printf("test done");
// 	}

// }
// int main()
// {
//     int  fd;
//     char *line;

//     fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
//     while ((line = get_next_line(fd)))
//         ft_putstr(line);
//     return (0);
// }
// char *read_line(FILE *file) {
//     if (file == NULL) {
//         return NULL;
//     }

//     size_t buffer_size = 128;  // Initial buffer size
//     size_t length = 0;
//     char *buffer = malloc(buffer_size * sizeof(char));

//     if (buffer == NULL) {
//         perror("malloc failed");
//         return NULL;
//     }

//     int c;
//     while ((c = fgetc(file)) != EOF && c != '\n') {
//         // Resize buffer if needed
//         if (length + 1 >= buffer_size) {
//             buffer_size *= 2;
//             char *new_buffer = realloc(buffer, buffer_size);
//             if (new_buffer == NULL) {
//                 perror("realloc failed");
//                 free(buffer);
//                 return NULL;
//             }
//             buffer = new_buffer;
//         }

//         buffer[length++] = (char)c;
//     }

//     // Handle EOF without any data read
//     if (length == 0 && c == EOF) {
//         free(buffer);
//         return NULL;
//     }

//     buffer[length] = '\0';  // Null-terminate the string
//     return buffer;
// }


// int	main() {
// 	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
// 	dup2(fd, 0);
// 	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
// 	char	*line;
// 	while ((line = read_line(fd)))
// 		printf("%s", line);
// }


// exercice 1 

// int main()
// {
// 	int fd[2];
// 	char buffer[100];
// 	char buffer_2[100];
// 	int pid;

// 	printf("entrer votre nom (max : 100 char) : ");
// 	fgets(buffer, 100, stdin);
// 	pipe(fd);
// 	write(fd[1], buffer, 100);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		read(fd[0], buffer_2, 100);
// 		printf("the string [%s] the lenght [%lu] \n", buffer_2 , strlen(buffer_2) - 1);
		
// 	}

// }

// int main()
// {
// 	int oldfd = open("ayoub.txt", O_WRONLY | O_CREAT, 0644);

// 	dup2(oldfd, 1);
// 	printf("oldfd is [%d]\n", oldfd);
// 	// printf("This message will be written to output.txt!\n");
//     // printf("So will this one!\n");
//  	fflush(stdout);
// }


// int ft_popen(const char *file, char *const argv[], char type)
// {
// 	int pid;
// 	int fd[2];
	

// 	//  read : 0
// 	// 	write : 1
// 	if (!file || !argv || (type != 'r' && type != 'w'))
// 		return (-1);
// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (type == 'r')
// 			dup2(fd[1], STDOUT_FILENO);
// 		else
// 			dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execvp(file, argv);
// 		exit(1);	
// 	}
// 	if(type == 'r')
// 	{
// 		close(fd[1]);
// 		return fd[0];
// 	}
// 	else
// 	{
// 		close(fd[0]);
// 		return fd[1];
// 	}
// }

int ft_popen(const char *file, char *const argv[], char type)
{
	int pid;
	int fd[2];

	if(!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	// read : 0;
	//  write : 1

	if (pipe(fd) == -1)
		return -1;
	pid = fork();
	if (pid == 0)
	{
		if (type == 'r')
			dup2(fd[1], STDOUT_FILENO);
		else
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	if(type == 'r')
	{
		close(fd[1]);
		return fd[0];
	}
	else
	{
		close(fd[0]);
		return fd[1];
	}
}

// int main()
// {
//     int  fd;
//     char *line;

//     fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
//     while ((line = get_next_line(fd)))
//         puts(line);
//     return (0);
// }





int    picoshell(char **cmds[])
{
	int fd[2];
	int pid;
	int i;
	int prev_fd;
	int status;
	int exit_code;

	exit_code = -1;
	prev_fd = -1;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd))
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return(1);
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) != -1)
					exit(1);
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) != -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if (cmds[i + 1])
		{
			close(fd[0]);
			prev_fd = fd[1];
		}
		i++;
	}
	while (wait(&status) != -1)
	{
		if(WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = 1;
	}
	return(exit_code);
	
	
}

// picoshell


#include <stdio.h>
#include <stdarg.h>
#include <string.h>
static int	count_cmds(int argc, char **argv)
{
	int	count = 1;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "|") == 0)
			count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

	int	cmd_count = count_cmds(argc, argv);
	char	***cmds = calloc(cmd_count + 1, sizeof(char **));
	if (!cmds)
		return (perror("calloc"), 1);

	int	i = 1, j = 0;
	while (i < argc)
	{
		int	len = 0;
		while (i + len < argc && strcmp(argv[i + len], "|") != 0)
			len++;
		cmds[j] = calloc(len + 1, sizeof(char *));
		if (!cmds[j])
			return (perror("calloc"), 1);
		for (int k = 0; k < len; k++)
			cmds[j][k] = argv[i + k];
		cmds[j][len] = NULL;
		i += len + 1;
		j++;
	}
	cmds[cmd_count] = NULL;

	int	ret = picoshell(cmds);

	// Clean up
	for (int i = 0; cmds[i]; i++)
		free(cmds[i]);
	free(cmds);

	return (ret);
}