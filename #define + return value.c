#include <Stdio.h>
#define SUM(x,y) ((x)+(y))
#define MAX(x,y) ((x)>(y))?(x):(y)
#define MULTIPLY(x,y) ((x)*(y))
#define PRINT(x) printf("%d",x); 

int function(int a, int b)
{
	if(a>b)
	{
		a = 100;
		return a;
	}
	
	
	else if(a<b)
	{
		b = 200;
		printf("function b = %d\n\n",b);
		return b;
	}
	
}



int main(void)
{
	int x = 5, y = 10,func=0;
	printf("%d\n%d\n%d\n",SUM(x,y),MAX(x,y),MULTIPLY(100,20));
	
	
	func = function(x, y);
	printf("x = %d, y = %d, return value = %d\n\n",x,y,func);
	return 0;
}
