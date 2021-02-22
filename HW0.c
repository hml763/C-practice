#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <malloc.h>
#include <stdlib.h>		//실행에 필요한 헤더파일 선언 

#define MAX_CUSTOMER 10000		//만번 실행시 최대 손님수로 정의. 

int duration = 30;			//30분이 1회 시뮬레이션 시간 
double arrival_prob_A = 0.7;	//큐 A에 도착할 확률 0.7, 아래는 각각 0.4, 0.3 
double arrival_prob_B = 0.4;
double arrival_prob_C = 0.3;

typedef struct {		//element라는 이름의 구조체 선언 
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct QueueNode{		//QueueNode라는 이름의 구조체 선언. 
	element item;				//위의 element형의 item이라는 이름을 가진 형이 존재. 
	struct QueueNode *link;		//안에 다음 link로 넘어가는 QueueNode 포인터형식의 링크변수선언. 
}QueueNode;	

typedef struct {
	QueueNode *front, *rear;		//QueueNode의 포인터형인 전,후면 선언 
}QueueType;
QueueType queue;		//이름을 queue라고 부름 약속. 

void error(const char *message){		//오류메세지  
	fprintf(stderr,"%s\n",message);
	exit(1);
}
	
void init(QueueType *q){		//초기화함수. front, rear둘다 NULL을 가리키라는 뜻. 
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q){			//만약 비었으면 q의 front 가리키는것이 비었으면 0반환.  
	return (q->front==NULL);		
}

void enqueue(QueueType *q, element item){		//연결된 큐 삽입하는 함수. 
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));		//동적메모리 할당. 
	
	if(temp == NULL)
		error("메모리를 할당할 수 없습니다");			//할당이 안됬다면 error문 출력. 
		
	else{										//할당이 됬다면 아래두줄을 먼저실행. 
		temp->item = item;						//temp의 item이 가리키는 것에 item 을 집어넣어라. 
		temp->link = NULL;						//temp의 link가 가리키는 것에 NULL을 집어넣어라. 
		
		if(is_empty(q)){						//만약 q가 비었다면 실행  
			q->front = temp;					//front 랑 rear랑에다가 temp값 넣음. 
			q->rear = temp;
		}
		
		else{
			q->rear->link = temp;		//비지 않았다면 이어지는 link에다가 temp에다가 연결. 
			q->rear = temp;
		}
	} 
}

element dequeue(QueueType *q){			//큐를 빼는 함수 
	QueueNode *temp = q->front;			// QueueNode 에다가 temp에다 넣음. 
	element item;						//element item 선언 
	if(is_empty(q))
		error("큐가 비어 있습니다"); 	//큐가 비었다면 error 출력 
	else{
		item = temp->item;				//item에다가 temp의 item이 가리키는 것을 넣는다.   
		q->front = q->front->link;		//q의 front에다가 다음 link가 가리키는 것을 집어넣는다. 
		if(q->front == NULL)			//q의 front가 NULL을 가리키면 rear도 NULL을 가리킨다. 
			q->rear = NULL;
		free(temp);						//동적메모리를 해제해준다. 
		return item;					//item을 리턴한다. 
	}
}

int main(){		
	int i;
	double tot_A=0,tot_B=0,tot_C=0,count_A=0,count_B=0,count_C=0;		//필요한 변수선언 
	srand((double)time(NULL));					//srand는 난수 반환에 영향을 주는데 사용될 이 seed 값을 주는 함수
	for(i=0;i<MAX_CUSTOMER;i++){				//10000번 돌리는 문. 
	int temp,i_A=1,i_B=1,i_C=1,sum_A=0,sum_B=0,sum_C=0; 	//for문 안에있어서 다시 새로 시작할때마다 초기값을 줌. 
	double tmp=0;
		while(sum_A<30){			//30번 반복문 
			element A;				//element 선언. 
			temp = (rand()%5 + 1);	//랜덤함수 이용 1부터 4까지 무작위로 고름. 
			tmp = ((double)rand())/(double)rand(); 	//랜덤함수 이용 0.1부터 1.0까지 무작위로 고름. 
			if(tmp <= arrival_prob_A){		//0.7보다 tmp값이 같거나 작아야 enqueue 가능. 
				enqueue(&queue,A);	
				sum_A = sum_A + temp;	//랜덤으로 나온 값을 계속 더한다. 
				i_A++;					//실행하는 동안 실행된 횟수 증가. 
				temp = 0;				//temp다시 0으로 초기화.		
			}
				
		}
		while(sum_B<30){
			element B;			
			temp = (rand()%6 + 4);		//랜덤함수 이용 4부터 6까지 무작위로 고름. 
			tmp = ((double)rand())/(double)rand();
			if(tmp <= arrival_prob_B){		//0.4보다 tmp값이 같거나 작아야 enqueue 가능. 
				enqueue(&queue, B);
				sum_B = sum_B + temp;
				i_B++;
				temp = 0;
			}
							
		}
		while(sum_C<30){
			element C;
			temp = rand()%8 + 3;		//랜덤함수 이용 3부터 7까지 무작위로 고름. 
			tmp = ((double)rand())/(double)rand();	
			if(tmp <= arrival_prob_C){		//0.3보다 tmp값이 같거나 작아야 enqueue 가능. 
				enqueue(&queue, C);
				sum_C = sum_C + temp;
				i_C++;
				temp = 0;
			}				
		}
		
		if(i_A > i_B){			//실행된 i_A횟수가 i_B횟수보다 클때 실행 
			if(i_A > i_C){			//실행된 i_A횟수가 i_C횟수보다 클때 실행 
				count_A++;			//count_A 1씩 증가. 
			}
			else if(i_C > i_A){			//실행된 i_C횟수가 i_A횟수보다 클때 실행
				count_C++;		//count_C 1씩 증가. 
			}	
			else{
				count_C = count_C + 0.5;			//실행된 i_A횟수와 i_B횟수가 같을 때 실행
				count_A = count_A + 0.5;
			}		
		}
		
		else if(i_B > i_A){
			if(i_B > i_C){
				count_B++;
			}
			else if(i_B < i_C){
				count_C++;
			}	
			else{
				count_C = count_C + 0.5;
				count_B = count_B + 0.5;
			}	
		}
		
		else{
			if(i_A == i_C){					//실행된 i_A횟수와 i_B횟수와 i_C횟수가 같을 때 실행
				count_A = count_A + 1/3;
				count_B = count_B + 1/3;
				count_C = count_C + 1/3;
			}
			
			else if(i_A < i_C){
				count_C++;
			}
			
			else{
				count_A = count_A + 0.5;
				count_B = count_B + 0.5;
			}
		}
		tot_A = tot_A + i_A;		//총 실행 갯수 구함  
		tot_B = tot_B + i_B;
		tot_C = tot_C + i_C;
	}
	printf("Queue A count : %.1f\nQueue B count : %.1f\nQueue C count : %.1f\n",count_A,count_B,count_C);
	printf("Queue A ave : %.1f\nQueue B ave : %.1f\nQueue C ave : %.1f\n",tot_A/10000,tot_B/10000,tot_C/10000);	//평균구함. 
}
