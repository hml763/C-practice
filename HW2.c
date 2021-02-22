#include <stdio.h>

int recur(int n,int sum){
	
	if(n>0){
		sum = n + sum;
		printf("%d\n",n);
		printf("sum : %d\n",sum);
		return recur(n-1,sum);
	}
	
}

int main()
{int sum;
	recur(5,sum);
}
