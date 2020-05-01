//#define _CRT_SECURE_NO_WARININGS
#include <Stdio.h>
#include <stdlib.h>  //문자열 변환, 의사 난수 생성, 동적 메모리 관리 등의 함수들을 포함하고 있다.

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
		printf("[%d/%d]점수 입력 : ",i+1,num);
		scanf("%d", &pointer_arr[i]);
	} 
	
	for(int i=0;i<num;++i){
		printf("%d번째 과목의 점수 : %d\n",i+1,pointer_arr[i]);
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

// main함수의 return 은 전체 다 종료, 특정함수의 return은 그 함수만 종료
//exit()은 stdlib에 내장, exit(1)은 error message 종료, exit(0)은 정상종료
 
