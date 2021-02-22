#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>			//exit 실행시키는 라이브러리 

typedef int element; 
typedef struct StackNode { 
	element item; 
	struct StackNode *link; 
} StackNode;

typedef struct { 
	StackNode *top; 
	} LinkedStackType;
	
//초기화함수 
void init(LinkedStackType *s) { 		//s의 top구조를 NULL로 초기화함. 
	s->top = NULL; }
	
// 공백상태 검출함수 
int is_empty(LinkedStackType *s) { 
	return (s->top == NULL); }			// LinkedStackType구조체가 NULL일 때 실행된다. 
//삽입 함수
void push(LinkedStackType *s, element item) { 
	StackNode *temp=(StackNode*)malloc(sizeof(StackNode)); 		//동적메모리 할당 
	if (temp==NULL) { 									//temp가 NULL일때 실행 
	fprintf(stderr,"메모리 할당에러\n"); 		//실행되는  출력문 
	return; } 
	
	else{ temp->item = item;			//NULL이 아닐때 실행됨. temp의 item변수에다 매개변수를 넣음. 
		  temp->link = s->top; 			//temp의 link포인터에다는 s의 top포인터를 넣어줌. 
		  s->top = temp; } 				//s의 top포인터에 받아들이는 값, temp를 넣어줌. 
}
		  
//삭제함수 
element pop(LinkedStackType *s) { 		 
	if( is_empty(s) ) { 	//empty 함수실행 해서 맞다면  아래의 실행문을 출력한다. 
		fprintf(stderr,"스택이 비어있음\n"); 
		//exit(1); 
		} 
		
	else{ 
		StackNode *temp=s->top; 		//StackNode형 temp를 생성하고 s의 top포인터를 넣는다. 
		element item = temp->item; 		//정수형 item에다 temp안의 item값을 넣는다. 
		s->top = s->top->link; 			//s의 top포인터에다 s의toplink를 넣어준다. 다음 포인터값이다. 
		free(temp); 					//동적메모리 할당한 값을 삭제해준다. 
		return item; 
		} 
	}

void display(LinkedStackType *s) {
	LinkedStackType *tmp=(LinkedStackType*)malloc(sizeof(LinkedStackType));		//LinkedStackType형 tmp로 동적메모리를 할당받아 선언해준다. 
	tmp->top = s->top;															//tmp의 top포인터에 매개변수 s의 top을 넣어준다. 	
	
	if(is_empty(s)){
		fprintf(stderr, "스택이 비어 있음\n");				//스택이 비었을 시 출력되는 문이다. 
		exit(1);
	}

	else{							
		while(s->top != NULL){			//s의 top포인터가 NULL이 아닐때 실행한다.  
			printf("%d\n",s->top->item);	//top이 가리키는 item을 출력한다. 
			s->top = s->top->link;			//다음 포인터를 가리키기위해  s의 top에다 link를 넣어준다. 
		}
		s->top = tmp->top;			//s의 top은 현재 스택의 마지막까지 내려갔으므로 다시 tmp의 top을 s로 넣어준다.  
		free(tmp);					//tmp의 메모리를 삭제해준다. 
	}
	puts("");
}

//스택에 저장되어 있는 요소들의 개수를 반환 
int get_height(LinkedStackType *s) {	
	int num=0;
	LinkedStackType *tmp=(LinkedStackType*)malloc(sizeof(LinkedStackType));		//새로운 동적메모리할당 
	tmp->top = s->top;				//tmp의 top포인터에 매개변수 s의 top을 넣어준다.  
	
	if(is_empty(s))					//스택이 비었을 시 출력되는 문이다. 
	{
		fprintf(stderr, "스택이 비어 있음\n");
		exit(1);
	}
	
	else{
		while(s->top != NULL){			//s의 top포인터가 NULL일때 실행 
			num++;						//실행될 때마다 num이 증가 
			s->top = s->top->link;		//s의 top에다 s의 top link값을 넣어준다. 
		}
	
		s->top = tmp->top;				//s의 top은 현재 스택의 마지막까지 내려갔으므로 다시 tmp의 top을 s로 넣어준다.  
		free(tmp);						//메모리를 할당해준 tmp를 삭제한다. 
	}
	
	return num;			//계산한 num값 반환 
}

//s가 가리키는 스택과 t가 가리키는 스택에 같은 데이터들이 똑같이 쌓여 있는지 확인한 후 같으면 1을 반환하고 같지 않으면 0을 반환 
int compare(LinkedStackType *s, LinkedStackType *t) {
	int i,number=0,j;			//변수선언 
	j = get_height(s)-2;		//함수제작중 시행착오끝에 get_height로는 정상적으로 실행이 안되어 j를 추가. 아래의 for문에서 get_height값이 정확하지 않아 정확한 출력을 위해첨가하였음. 
	while(s->top != NULL && t->top != NULL)			//s,t의 top값이 NULL이 되지않을때 실행 
	{		
		if(get_height(s) != get_height(t))			//두 스택값이 다르면 무조건 0반환 
			return 0;
		
		if(s->top->item == t->top->item){
			
			for(i=0;i<get_height(s)+j;i++){			//get_height에다 j값을 더한 것만큼 각각의 스택에 pop 실행하여 비교. 
				pop(s);
				pop(t);
				
				if(s->top->item != t->top->item){		//두개의 스택값이 다를떄 0반환 
					return 0;
				}
			
				else{
					number = 1;		//같을시 변수에다 1 넣어줌. 
				}
			}		
		}
		
		else
			return 0;			//스택값이 다를시 0반환  
		
		return number;			//변수 반환. 
	}
	
		
}
// 메인함수, 아래는 하나의 예시이고 각자 위의 함수들을 구현한 후 메인 함수를 적절히 작성해서 테스트해 볼 것, 메인함수는 제출하지 않음 

int main() { 
	LinkedStackType m, t; 

	init(&m); 
	init(&t);
	 
	push(&m,2); 
	push(&m,2); 
	push(&m,2); 
	push(&m,2); 
	
	
	push(&t,1); 
	push(&t,2); 
	push(&t,3); 
	push(&t,4); 
	push(&t,5); 


	display(&m); 
	display(&t); 

	
	printf("height of m=\t%d\theight of t=\t%d\n", get_height(&m), get_height(&t)); 
	printf("result_of_compare\t%d\n", compare(&m,&t)); 
	
}
