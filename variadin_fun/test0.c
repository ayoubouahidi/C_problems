#include <stdarg.h>
#include <stdio.h>


int	sum(int nbr, int nbr1, ...)
{
	int s = 0;
	int i = 0;

	va_list list;
	va_start(list, nbr1);
	// printf("%d\n", );
	while (i < nbr)
	{
		int x = va_arg(list, int);
		s += x;
		i++;
	}
	return (s);
}

int main()
{
	printf("%p", "ayoub");
	// printf("the sum is : %d\n", sum(4,4,2,4));
}