#include <Stdio.h>

int main()
{
	int arr[5] = {1,2,3,4,5};
	int (*p)[5] = &arr;
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("%3d",*((*p) + i));	//(*p)[i] 해도되고 arr 해도됨 
	}    		
}
