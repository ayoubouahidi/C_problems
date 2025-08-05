static int b = 10;
int		test()
{
	static int a;
	a++;
	b +=  10;
	printf("%d  %d\n",	a, b);
	return a;
}


int		main()
{
	static int c;
	printf("%d\n",test());
	printf("%d\n",test());
	printf("%d\n",test());
	printf("%d\n", b);
	
}


