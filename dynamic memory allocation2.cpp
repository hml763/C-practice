//#define _CRT_SECURE_NO_WARININGS
#include <Stdio.h>
#include <stdlib.h>  //���ڿ� ��ȯ, �ǻ� ���� ����, ���� �޸� ���� ���� �Լ����� �����ϰ� �ִ�.

int main(void){
	int num;
	int ave,k = 0;
	int *pointer_arr;
	printf("How many courses will you save? ");
	scanf("%d",&num);
	
	if(num==0){
		printf("you typed 0\n");		
		return 0;
	}
	
	pointer_arr = (int*)malloc(sizeof(int) * num);
	
	if(pointer_arr = NULL){
		printf("malloc ERROR\n");
		exit(1);
	}
		
	for(int i=0; i<num; ++i){
		printf("[%d/%d]���� �Է� : ",i+1,num);
		scanf("%d", &pointer_arr[i]);
	} 
	
	for(int i=0;i<num;++i){
		printf("%d��° ������ ���� : %d\n",i+1,pointer_arr[i]);
	}
	
	for(int i=0;i<num;++i){
		ave += pointer_arr[i];
	}
	
	ave /= num;
	printf("average : %d\n",ave);
	
	free(pointer_arr);
	system("pause");
	return 0;
}

// main�Լ��� return �� ��ü �� ����, Ư���Լ��� return�� �� �Լ��� ����
//exit()�� stdlib�� ����, exit(1)�� error message ����, exit(0)�� ��������
 
