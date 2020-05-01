#include <stdio.h>

int is_odd(int n);
int is_even(int n);

int main(){
	
	int num[10];
	int i=0,even=0,odd=0;
	printf("정수를 빈칸으로 구분해서 입력하세요.(마지막에 0 입력)\n");

	for(i=0;i<100;i++){
		scanf("%d",&num[i]);
				
		if(is_odd(num[i])==1)
			odd++;
		
		if(is_even(num[i])==1)
			even++;
		
		if(num[i]==0)
			break;
	}
	
	printf("\n입력받은 정수중 짝수는 %d개, 홀수는 %d개 입니다.\n ",even,odd);	
	return 0;
}

int is_odd(int n){
	int odd=0;
	if(n%2 == 1)
		odd=1;	
	
	return odd;
}

int is_even(int n){
	int even = 0;
	if(n%2 == 0)
		even=1;
	
	return even;
}



