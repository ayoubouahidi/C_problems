#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int	main()
{
	int	fd0;
	int	fd1;
	char str[20];
	int i = 0;
	

	fd0 = open("file.txt", O_RDWR);
	fd1 = open("file.txt", O_RDONLY);
	if (fd0 != -1)
	{
		printf("%d\n", fd0);
		size_t b = read(fd0, str, sizeof(str));
		str[b] = '\0';
		printf("%s\n|number of char : %d\n", str, b);

		while (str[i] != '\0')
		{
			if(str[i] == '\n')
				printf("i found a new line \n");
			i++;
		}
	}
	printf("test done !");
	return 0;
}