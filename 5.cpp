#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int devisor(int n){
	int i=0,number=0;
	
	printf("%d의 약수 : ",n);
	
	for(i=1; i<n+1; i++){
		if(n % i == 0){
			printf("%d ", i);
			number++;
		}
	}
	printf("=> 총 %d 개\n", number); 
}

int main(){

	srand(time(NULL));	
	int i=0,num=0;
	
	printf("3개의 난수의 약수를 출력하는 프로그램\n\n");
	
	for(i=0;i<3;i++){
		num=rand()%1000;
		devisor(num);
	}
	
	return 0;
}
