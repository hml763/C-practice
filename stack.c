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
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode)); 		//동적메모리 할당 
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
	LinkedStackType *tmp = (LinkedStackType*)malloc(sizeof(LinkedStackType));		//LinkedStackType형 tmp로 동적메모리를 할당받아 선언해준다. 
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
	LinkedStackType *tmp = (LinkedStackType*)malloc(sizeof(LinkedStackType));		//새로운 동적메모리할당 
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
	LinkedStackType *stack_s = (LinkedStackType*)malloc(sizeof(LinkedStackType));			//각각 stack_s, stack_t라는 이름으로 동적메모리할당  
	LinkedStackType *stack_t = (LinkedStackType*)malloc(sizeof(LinkedStackType));
	int num=0;
	stack_s->top = s->top;		//할당한 메모리의 top에다 s의 top을 넣어줌 
	stack_t->top = t->top;
	
	if(is_empty(s) || is_empty(t))		//둘중하나라도 비었다면 exit함수 실행.  
	{
		fprintf(stderr, "스택이 비어 있음\n");
		exit(1);
	}	
	
	else
	{
		while(s->top != NULL)		//밑에 if함수 때문에 조건을 s 스택 하나만 빈값이 아니라고 넣었음. 
		{
			if(get_height(s) != get_height(t))		//두 스택의 길이가 다르다면 바로 0반환.  
				return 0;
			
			if(s->top->item == t->top->item)		//두개 스택의 item값이 같을시 실행 
			{
				num++;						//num이 1씩 증가. 
				s->top = s->top->link;		//다음 링크로 넘어가게끔 해주는 명령어. 
				t->top = t->top->link;	
			}
			
			else
			{
				return 0;				//if문이 아닐시 0반환 
			}
		
		}
	}
	
	s->top = stack_s->top;				//받앗던 s스택에 다시 할당했던 메모리의 top의 값을 넣어줌. 밑에도 마찬가지.  
	t->top = stack_t->top;			
	free(stack_s);					//할당했던 메모리 삭제. 
	free(stack_t);
		
	if(num > 0)			//위에서 증가했던 num이 0보다 크면 1반환. 
		return 1;
	
	else
		return 0;		//아닐시 0반환. 	
}

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
