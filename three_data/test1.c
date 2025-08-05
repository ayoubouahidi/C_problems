#include "test1.h"


t_three *new_node(int val)
{
	t_three *three;

	three = malloc(sizeof(three));
	three->val = val;
	three->left = NULL;
	three->right = NULL;
	return (three);
}


int main()
{
	t_three *three;
	three = new_node(1);
	printf("value in left %d\n", three->val);	 
}
