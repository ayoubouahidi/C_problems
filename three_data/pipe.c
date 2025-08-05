#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	int buffer[20];

	if (pipe(fd) == -1)
	{
		printf("error in pipe");
		return (1);
	}
	
}