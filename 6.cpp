#include <stdio.h>

int is_odd(int n);
int is_even(int n);

int main(){
	
	int num[10];
	int i=0,even=0,odd=0;
	printf("������ ��ĭ���� �����ؼ� �Է��ϼ���.(�������� 0 �Է�)\n");

	for(i=0;i<100;i++){
		scanf("%d",&num[i]);
				
		if(is_odd(num[i])==1)
			odd++;
		
		if(is_even(num[i])==1)
			even++;
		
		if(num[i]==0)
			break;
	}
	
	printf("\n�Է¹��� ������ ¦���� %d��, Ȧ���� %d�� �Դϴ�.\n ",even,odd);	
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



