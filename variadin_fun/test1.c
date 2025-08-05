#include <stdio.h>
#include <stdarg.h>


void	print_strings(char sep, int num, ...)
{
	va_list list;
	va_start(list, num);
	int i = 0;
	while (i < num)
	{
		if (i != 0 && sep && i != num -1 )
			printf("%c", sep);
		char *str = va_arg(list, char *);
		if (str != NULL)
		{
			printf("%s", str);
		}
		i++;
	}
	va_end(list);
	printf("\n");
}
int	main()
{
	print_strings(',', 3, "ayoub", "ouahidi", NULL);
}