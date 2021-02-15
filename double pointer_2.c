#include <Stdio.h>

int main()
{
	int i = 100;
	int *p = &i;	//*p == i 
	int **q = &p;	//**q == p
	
	*p = 200;
	printf("i = %d\n",i);
	
	**q = 300;
	printf("i = %d\n\n",i);
}
