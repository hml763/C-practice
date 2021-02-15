#include <Stdio.h>
#include <stdlib.h>

int main(void)
{
	int size,sum = 0,i;
	int *arr = NULL;
	double average = 0.0;
	
	printf("How many integers are you going to type? : ");
	scanf("%d",&size);
	
	arr = malloc(sizeof(int) *size);
	if(arr==NULL)
	{
		printf("dynamic memory allocation failed\n");
		return -1;
	}
	
	printf("type in %d integers : ",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<size;i++)
 		sum = sum + arr[i];
	
	average = (double)sum / (double)size;
	printf("sum : %d, average : %f\n",sum,average);
	free(arr);
	arr = NULL;
	
	return 0;
		
} 
