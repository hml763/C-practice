#include <stdio.h>
#include <stdlib.h>

int main(void){
	int arr[4] = {1,2,3,4};
	int* pointer_arr;
	
	pointer_arr = (int *)malloc(sizeof(int)*4); //�����޸� �Ҵ�;  
	// int Ÿ�Ի�����(4byte) 4��ŭ�� �޸𸮸� �Ҵ��϶� 
	
	if(pointer_arr == NULL)
		printf("Malloc Error\n");
		
	for(int i=0;i<4;i++)
		pointer_arr[i] = arr[i];
		
	for(int i=0;i<4;i++)
		printf("%d \n",pointer_arr[i]);
		
	
	free(pointer_arr); //�Ҵ�� �޸� ���� 
	system("pause");
	return 0;
}


/*c ���α׷��� �ۼ��ϰ� �����Ű��
��°���� ���Ѻ�������� Ȯ���ϱ⵵ ���� �ٷ� �ܼ�â�� ������ ��찡 �ִµ� 
���߰� ���� ���� ������ ���� = system pause -> ����Ϸ��� �ƹ�Ű�� �����ʽÿ� ����*/
