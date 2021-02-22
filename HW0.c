#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <malloc.h>
#include <stdlib.h>		//���࿡ �ʿ��� ������� ���� 

#define MAX_CUSTOMER 10000		//���� ����� �ִ� �մԼ��� ����. 

int duration = 30;			//30���� 1ȸ �ùķ��̼� �ð� 
double arrival_prob_A = 0.7;	//ť A�� ������ Ȯ�� 0.7, �Ʒ��� ���� 0.4, 0.3 
double arrival_prob_B = 0.4;
double arrival_prob_C = 0.3;

typedef struct {		//element��� �̸��� ����ü ���� 
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct QueueNode{		//QueueNode��� �̸��� ����ü ����. 
	element item;				//���� element���� item�̶�� �̸��� ���� ���� ����. 
	struct QueueNode *link;		//�ȿ� ���� link�� �Ѿ�� QueueNode ������������ ��ũ��������. 
}QueueNode;	

typedef struct {
	QueueNode *front, *rear;		//QueueNode�� ���������� ��,�ĸ� ���� 
}QueueType;
QueueType queue;		//�̸��� queue��� �θ� ���. 

void error(const char *message){		//�����޼���  
	fprintf(stderr,"%s\n",message);
	exit(1);
}
	
void init(QueueType *q){		//�ʱ�ȭ�Լ�. front, rear�Ѵ� NULL�� ����Ű��� ��. 
	q->front = q->rear = NULL;
}

int is_empty(QueueType *q){			//���� ������� q�� front ����Ű�°��� ������� 0��ȯ.  
	return (q->front==NULL);		
}

void enqueue(QueueType *q, element item){		//����� ť �����ϴ� �Լ�. 
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));		//�����޸� �Ҵ�. 
	
	if(temp == NULL)
		error("�޸𸮸� �Ҵ��� �� �����ϴ�");			//�Ҵ��� �ȉ�ٸ� error�� ���. 
		
	else{										//�Ҵ��� ��ٸ� �Ʒ������� ��������. 
		temp->item = item;						//temp�� item�� ����Ű�� �Ϳ� item �� ����־��. 
		temp->link = NULL;						//temp�� link�� ����Ű�� �Ϳ� NULL�� ����־��. 
		
		if(is_empty(q)){						//���� q�� ����ٸ� ����  
			q->front = temp;					//front �� rear�����ٰ� temp�� ����. 
			q->rear = temp;
		}
		
		else{
			q->rear->link = temp;		//���� �ʾҴٸ� �̾����� link���ٰ� temp���ٰ� ����. 
			q->rear = temp;
		}
	} 
}

element dequeue(QueueType *q){			//ť�� ���� �Լ� 
	QueueNode *temp = q->front;			// QueueNode ���ٰ� temp���� ����. 
	element item;						//element item ���� 
	if(is_empty(q))
		error("ť�� ��� �ֽ��ϴ�"); 	//ť�� ����ٸ� error ��� 
	else{
		item = temp->item;				//item���ٰ� temp�� item�� ����Ű�� ���� �ִ´�.   
		q->front = q->front->link;		//q�� front���ٰ� ���� link�� ����Ű�� ���� ����ִ´�. 
		if(q->front == NULL)			//q�� front�� NULL�� ����Ű�� rear�� NULL�� ����Ų��. 
			q->rear = NULL;
		free(temp);						//�����޸𸮸� �������ش�. 
		return item;					//item�� �����Ѵ�. 
	}
}

int main(){		
	int i;
	double tot_A=0,tot_B=0,tot_C=0,count_A=0,count_B=0,count_C=0;		//�ʿ��� �������� 
	srand((double)time(NULL));					//srand�� ���� ��ȯ�� ������ �ִµ� ���� �� seed ���� �ִ� �Լ�
	for(i=0;i<MAX_CUSTOMER;i++){				//10000�� ������ ��. 
	int temp,i_A=1,i_B=1,i_C=1,sum_A=0,sum_B=0,sum_C=0; 	//for�� �ȿ��־ �ٽ� ���� �����Ҷ����� �ʱⰪ�� ��. 
	double tmp=0;
		while(sum_A<30){			//30�� �ݺ��� 
			element A;				//element ����. 
			temp = (rand()%5 + 1);	//�����Լ� �̿� 1���� 4���� �������� ��. 
			tmp = ((double)rand())/(double)rand(); 	//�����Լ� �̿� 0.1���� 1.0���� �������� ��. 
			if(tmp <= arrival_prob_A){		//0.7���� tmp���� ���ų� �۾ƾ� enqueue ����. 
				enqueue(&queue,A);	
				sum_A = sum_A + temp;	//�������� ���� ���� ��� ���Ѵ�. 
				i_A++;					//�����ϴ� ���� ����� Ƚ�� ����. 
				temp = 0;				//temp�ٽ� 0���� �ʱ�ȭ.		
			}
				
		}
		while(sum_B<30){
			element B;			
			temp = (rand()%6 + 4);		//�����Լ� �̿� 4���� 6���� �������� ��. 
			tmp = ((double)rand())/(double)rand();
			if(tmp <= arrival_prob_B){		//0.4���� tmp���� ���ų� �۾ƾ� enqueue ����. 
				enqueue(&queue, B);
				sum_B = sum_B + temp;
				i_B++;
				temp = 0;
			}
							
		}
		while(sum_C<30){
			element C;
			temp = rand()%8 + 3;		//�����Լ� �̿� 3���� 7���� �������� ��. 
			tmp = ((double)rand())/(double)rand();	
			if(tmp <= arrival_prob_C){		//0.3���� tmp���� ���ų� �۾ƾ� enqueue ����. 
				enqueue(&queue, C);
				sum_C = sum_C + temp;
				i_C++;
				temp = 0;
			}				
		}
		
		if(i_A > i_B){			//����� i_AȽ���� i_BȽ������ Ŭ�� ���� 
			if(i_A > i_C){			//����� i_AȽ���� i_CȽ������ Ŭ�� ���� 
				count_A++;			//count_A 1�� ����. 
			}
			else if(i_C > i_A){			//����� i_CȽ���� i_AȽ������ Ŭ�� ����
				count_C++;		//count_C 1�� ����. 
			}	
			else{
				count_C = count_C + 0.5;			//����� i_AȽ���� i_BȽ���� ���� �� ����
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
			if(i_A == i_C){					//����� i_AȽ���� i_BȽ���� i_CȽ���� ���� �� ����
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
		tot_A = tot_A + i_A;		//�� ���� ���� ����  
		tot_B = tot_B + i_B;
		tot_C = tot_C + i_C;
	}
	printf("Queue A count : %.1f\nQueue B count : %.1f\nQueue C count : %.1f\n",count_A,count_B,count_C);
	printf("Queue A ave : %.1f\nQueue B ave : %.1f\nQueue C ave : %.1f\n",tot_A/10000,tot_B/10000,tot_C/10000);	//��ձ���. 
}
