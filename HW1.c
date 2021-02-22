#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode {		// 연결 리스트의 노드의 구조 
	int row;
	int col; 
	int value; 
	
	struct ListNode *link; 
} ListNode;
	
typedef struct ListHeader { 	// 연결 리스트 헤더 
	int rows; 
	int cols; 
	int terms; 
	ListNode *head; 			//단일연결리스트의 head부분을 포인터로 받음  
	ListNode *tail; 			//단일연결리스트의 tail부분을 포인터로 받음  
} ListHeader;

void init(ListHeader *mlist, int rows, int cols) {	 // 초기화 함수  
	mlist->rows = rows;					//매개변수row를 mlist의 구조 row에다 넣음.  
	mlist->cols = cols; 				//매개변수col를 mlist의 구조 col에다 넣음.  
	mlist->terms = 0; 					//mlist의 구조 terms에다 초기값 0을 넣음 
	mlist->head = mlist->tail = NULL;	//처음 헤드와 테일에다 NULL값을 넣음. 
}

void error(char *message)		//error함수 선언 
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

void insert_node_last(ListHeader *mlist, int row, int col, int value) { 	// 단순 연결 리스트의 마지막에 노드를 추가 하는 함수  
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));	//포인터 temp로 동적메모리할당 
	if( temp == NULL ) 		//포인터 temp구조가 NULL일때 
	{
		error("메모리 할당 에러"); 	//위의 error함수 실행 
	}
	
	temp->row = row;		//temp의 row구조에 매개변수 row를 넣음  
	temp->col = col; 		//temp의 col구조에 매개변수 col를 넣음  
	temp->value = value; 	//temp의 value구조에 매개변수 value를 넣음  
	temp->link = NULL; 		//temp의 link구조에 NULL을  넣음  
	
	if( mlist->tail == NULL ) { 	//mlist의 tail이 NULL일시 처음에 실행되는 부분이다. 
		mlist->head = temp;			//mlist의 헤드부분에 temp를 삽입한다. 
		mlist->tail = temp; 		//mlist의 테일부분또한 temp를 삽입한다. 
	}
	
	else { 							//mlist의 tail이 NULL이 아닐시. 처음이아닌 다음부터 실행되는 부분이다. 
		mlist->tail->link = temp;	//연결되는 포인터인 링크에다 다음주소인 temp를 넣어준다. 
		mlist->tail = temp; 		//또한 tail에다가도 temp를 넣어준다. 
	} 

	mlist->terms++; 				//terms는 0에서 부터 함수가 실행될수록 1씩 증가한다. 
}

void matrix_add(ListHeader *mlist1, ListHeader *mlist2, ListHeader *mlist3 )//matrix3 = matrix1 + matrix2함수 
{
	ListNode *a = mlist1->head;			//a에다가 매개변수 mlist1의 head를 넣어준다. 
	ListNode *b = mlist2->head;			//b에다가 매개변수 mlist2의 head를 넣어준다. 
	int sum;							//전역변수 sum선언 
	
	while(a!=NULL && b!=NULL)			//a,b둘다 NULL이 아닐때까지 실행 
	{									
		
		if(a->row == b->row)			//a의 row와 b의 row가 같을시 실행 
		{
			if(a->col == b->col){		//a의 col와 b의 col가 같을시 실행 
				sum = a->value + b->value;		//sum에다 a,b의 value값을 더한것을 넣는다.  
				insert_node_last(mlist3,a->row,a->col,sum);		//insert함수를 호출해서 mlist3에다 a의row, col, value값을 넣고 저장한다.   
				a = a->link;									//a(헤드)에다가 a의 link를 넣어서 다음 노드로 연결시켜준다. 아래도 마찬가지. 
				b = b->link;
			}	
			
			else 
			{
				if(a->col > b->col ){
					sum = b->value;									//sum에다 b의 value값을 넣는다. 
					insert_node_last(mlist3,a->row,b->col,sum);		//insert함수를 호출해서 mlist3에다 b의row, col, value값을 넣고 저장한다.  
					b = b->link;									//b(헤드)에다가 b의 link를 넣어서 다음 노드로 연결시켜준다.
				}
				
				else 
				{
					sum = a->value;									//sum에다 a의 value값을 넣는다.
					insert_node_last(mlist3,a->row,a->col,sum);		//insert함수를 호출해서 mlist3에다 a의row, col, value값을 넣고 저장한다.  
					a = a->link;									//a(헤드)에다가 a의 link를 넣어서 다음 노드로 연결시켜준다.
				}
				
			}	//tail은 마지막에 시작하는 주소값을 확인하는데씀  
			
		}
		
		else
		{
			if(a->row > b->row){
					sum = b->value;									//sum에다 b의 value값을 넣는다.
					insert_node_last(mlist3,b->row,b->col,sum);		//insert함수를 호출해서 mlist3에다 b의row, col, value값을 넣고 저장한다.  
					b = b->link;									//b(헤드)에다가 b의 link를 넣어서 다음 노드로 연결시켜준다.
				}
				
			else{
					sum = a->value;									//sum에다 a의 value값을 넣는다.
					insert_node_last(mlist3,a->row,a->col,sum);		//insert함수를 호출해서 mlist3에다 a의row, col, value값을 넣고 저장한다.  
					a = a->link; 									//a(헤드)에다가 a의 link를 넣어서 다음 노드로 연결시켜준다.
				}
		}
		
		if(a!=NULL)
		{
			for(;a!=NULL;a=a->link){							//a(헤드)에다가 a의 link를 넣어서 다음 노드로 연결시켜주고 a가 NULL이 아닐때까지 실행한다.  
				sum = a->value;									//sum에다 a의 value값을 넣는다.
				insert_node_last(mlist3,a->row,a->col,sum);		//insert함수를 호출해서 mlist3에다 a의row, col, value값을 넣고 저장한다.  
		
			}		
		}
		
		if(b!=NULL)
		{
			for(;b!=NULL;b=b->link){							//b(헤드)에다가 b의 link를 넣어서 다음 노드로 연결시켜주고 b가 NULL이 아닐때까지 실행한다. 
				sum = b->value;									//sum에다 b의 value값을 넣는다.
				insert_node_last(mlist3,b->row,b->col,sum);		//insert함수를 호출해서 mlist3에다 b의row, col, value값을 넣고 저장한다.  
			}		
		}
	}
}  

void matrix_print(ListHeader *mlist,int num)				//matrix출력 함수 matrix번호를 출력하기위해 정수형 변수 num을 추가하였다. 
{
	ListNode *p = mlist->head;								//Listnode구조 포인터 p에다가 mlist head부분을 넣는다. 
	printf("matrix %d\n",num);								//추가한 num을 이용해서 matrix번호를 준다. 
	
	for(;p;p=p->link){										//위에 선언한 p를 이용해서 p에다 p의 링크를 넣는다. 
		printf("%d, (%d,%d)\n",p->value,p->row,p->col);		//처음부터 p의 value값, row, col순으로 출력한다.	
	}
	puts("");		//enter역할을한다. 

}

int main() { 
	ListHeader m1, m2, m3;
	
	init(&m1,4,4); 
	init(&m2,4,4); 
	init(&m3,4,4);
	
	insert_node_last(&m1,0,1,3); 
	insert_node_last(&m1,1,3,5); 
	insert_node_last(&m1,2,0,-5); 
	insert_node_last(&m1,3,1,10);
	
	insert_node_last(&m2,0,1,8); 
	insert_node_last(&m2,1,0,9); 
	insert_node_last(&m2,1,2,4);
	
	matrix_add(&m1,&m2,&m3);
	
	matrix_print(&m1,1); 
	matrix_print(&m2,2); 
	printf("matrix1 + matrix2 = matrix3\n\n");
	matrix_print(&m3,3);
} 

