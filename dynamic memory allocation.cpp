#include <stdio.h>
#include <stdlib.h>

int main(void){
	int arr[4] = {1,2,3,4};
	int* pointer_arr;
	
	pointer_arr = (int *)malloc(sizeof(int)*4); //동적메모리 할당;  
	// int 타입사이즈(4byte) 4만큼의 메모리를 할당하라 
	
	if(pointer_arr == NULL)
		printf("Malloc Error\n");
		
	for(int i=0;i<4;i++)
		pointer_arr[i] = arr[i];
		
	for(int i=0;i<4;i++)
		printf("%d \n",pointer_arr[i]);
		
	
	free(pointer_arr); //할당된 메모리 해제 
	system("pause");
	return 0;
}


/*c 프로그램을 작성하고 실행시키면
출력결과를 지켜보고싶은데 확인하기도 전에 바로 콘솔창이 꺼지는 경우가 있는데 
멈추고 싶은 곳에 넣으면 멈춤 = system pause -> 계속하려면 아무키나 누르십시오 나옴*/
