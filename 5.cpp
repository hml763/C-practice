#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int devisor(int n){
	int i=0,number=0;
	
	printf("%d�� ��� : ",n);
	
	for(i=1; i<n+1; i++){
		if(n % i == 0){
			printf("%d ", i);
			number++;
		}
	}
	printf("=> �� %d ��\n", number); 
}

int main(){

	srand(time(NULL));	
	int i=0,num=0;
	
	printf("3���� ������ ����� ����ϴ� ���α׷�\n\n");
	
	for(i=0;i<3;i++){
		num=rand()%1000;
		devisor(num);
	}
	
	return 0;
}
