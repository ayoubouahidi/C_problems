#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


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

int	ft_popen(const char *file, char *const argv[], char type)
{
	int	fds[2];
	pid_t pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fds) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fds[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else
		{
			if (dup2(fds[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fds[0]);
		close(fds[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fds[1]);
		return fds[0];
	}
	else
	{
		close(fds[0]);
		return fds[1];
	}
}
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
char *read_line(FILE *file) {
    if (file == NULL) {
        return NULL;
    }

    size_t buffer_size = 128;  // Initial buffer size
    size_t length = 0;
    char *buffer = malloc(buffer_size * sizeof(char));

    if (buffer == NULL) {
        perror("malloc failed");
        return NULL;
    }

    int c;
    while ((c = fgetc(file)) != EOF && c != '\n') {
        // Resize buffer if needed
        if (length + 1 >= buffer_size) {
            buffer_size *= 2;
            char *new_buffer = realloc(buffer, buffer_size);
            if (new_buffer == NULL) {
                perror("realloc failed");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[length++] = (char)c;
    }

    // Handle EOF without any data read
    if (length == 0 && c == EOF) {
        free(buffer);
        return NULL;
    }

    buffer[length] = '\0';  // Null-terminate the string
    return buffer;
}


int	main() {
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char	*line;
	while ((line = read_line(fd)))
		printf("%s", line);
}