#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode {		// ���� ����Ʈ�� ����� ���� 
	int row;
	int col; 
	int value; 
	
	struct ListNode *link; 
} ListNode;
	
typedef struct ListHeader { 	// ���� ����Ʈ ��� 
	int rows; 
	int cols; 
	int terms; 
	ListNode *head; 			//���Ͽ��Ḯ��Ʈ�� head�κ��� �����ͷ� ����  
	ListNode *tail; 			//���Ͽ��Ḯ��Ʈ�� tail�κ��� �����ͷ� ����  
} ListHeader;

void init(ListHeader *mlist, int rows, int cols) {	 // �ʱ�ȭ �Լ�  
	mlist->rows = rows;					//�Ű�����row�� mlist�� ���� row���� ����.  
	mlist->cols = cols; 				//�Ű�����col�� mlist�� ���� col���� ����.  
	mlist->terms = 0; 					//mlist�� ���� terms���� �ʱⰪ 0�� ���� 
	mlist->head = mlist->tail = NULL;	//ó�� ���� ���Ͽ��� NULL���� ����. 
}

void error(char *message)		//error�Լ� ���� 
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

void insert_node_last(ListHeader *mlist, int row, int col, int value) { 	// �ܼ� ���� ����Ʈ�� �������� ��带 �߰� �ϴ� �Լ�  
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));	//������ temp�� �����޸��Ҵ� 
	if( temp == NULL ) 		//������ temp������ NULL�϶� 
	{
		error("�޸� �Ҵ� ����"); 	//���� error�Լ� ���� 
	}
	
	temp->row = row;		//temp�� row������ �Ű����� row�� ����  
	temp->col = col; 		//temp�� col������ �Ű����� col�� ����  
	temp->value = value; 	//temp�� value������ �Ű����� value�� ����  
	temp->link = NULL; 		//temp�� link������ NULL��  ����  
	
	if( mlist->tail == NULL ) { 	//mlist�� tail�� NULL�Ͻ� ó���� ����Ǵ� �κ��̴�. 
		mlist->head = temp;			//mlist�� ���κп� temp�� �����Ѵ�. 
		mlist->tail = temp; 		//mlist�� ���Ϻκж��� temp�� �����Ѵ�. 
	}
	
	else { 							//mlist�� tail�� NULL�� �ƴҽ�. ó���̾ƴ� �������� ����Ǵ� �κ��̴�. 
		mlist->tail->link = temp;	//����Ǵ� �������� ��ũ���� �����ּ��� temp�� �־��ش�. 
		mlist->tail = temp; 		//���� tail���ٰ��� temp�� �־��ش�. 
	} 

	mlist->terms++; 				//terms�� 0���� ���� �Լ��� ����ɼ��� 1�� �����Ѵ�. 
}

void matrix_add(ListHeader *mlist1, ListHeader *mlist2, ListHeader *mlist3 )//matrix3 = matrix1 + matrix2�Լ� 
{
	ListNode *a = mlist1->head;			//a���ٰ� �Ű����� mlist1�� head�� �־��ش�. 
	ListNode *b = mlist2->head;			//b���ٰ� �Ű����� mlist2�� head�� �־��ش�. 
	int sum;							//�������� sum���� 
	
	while(a!=NULL && b!=NULL)			//a,b�Ѵ� NULL�� �ƴҶ����� ���� 
	{									
		
		if(a->row == b->row)			//a�� row�� b�� row�� ������ ���� 
		{
			if(a->col == b->col){		//a�� col�� b�� col�� ������ ���� 
				sum = a->value + b->value;		//sum���� a,b�� value���� ���Ѱ��� �ִ´�.  
				insert_node_last(mlist3,a->row,a->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� a��row, col, value���� �ְ� �����Ѵ�.   
				a = a->link;									//a(���)���ٰ� a�� link�� �־ ���� ���� ��������ش�. �Ʒ��� ��������. 
				b = b->link;
			}	
			
			else 
			{
				if(a->col > b->col ){
					sum = b->value;									//sum���� b�� value���� �ִ´�. 
					insert_node_last(mlist3,a->row,b->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� b��row, col, value���� �ְ� �����Ѵ�.  
					b = b->link;									//b(���)���ٰ� b�� link�� �־ ���� ���� ��������ش�.
				}
				
				else 
				{
					sum = a->value;									//sum���� a�� value���� �ִ´�.
					insert_node_last(mlist3,a->row,a->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� a��row, col, value���� �ְ� �����Ѵ�.  
					a = a->link;									//a(���)���ٰ� a�� link�� �־ ���� ���� ��������ش�.
				}
				
			}	//tail�� �������� �����ϴ� �ּҰ��� Ȯ���ϴµ���  
			
		}
		
		else
		{
			if(a->row > b->row){
					sum = b->value;									//sum���� b�� value���� �ִ´�.
					insert_node_last(mlist3,b->row,b->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� b��row, col, value���� �ְ� �����Ѵ�.  
					b = b->link;									//b(���)���ٰ� b�� link�� �־ ���� ���� ��������ش�.
				}
				
			else{
					sum = a->value;									//sum���� a�� value���� �ִ´�.
					insert_node_last(mlist3,a->row,a->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� a��row, col, value���� �ְ� �����Ѵ�.  
					a = a->link; 									//a(���)���ٰ� a�� link�� �־ ���� ���� ��������ش�.
				}
		}
		
		if(a!=NULL)
		{
			for(;a!=NULL;a=a->link){							//a(���)���ٰ� a�� link�� �־ ���� ���� ��������ְ� a�� NULL�� �ƴҶ����� �����Ѵ�.  
				sum = a->value;									//sum���� a�� value���� �ִ´�.
				insert_node_last(mlist3,a->row,a->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� a��row, col, value���� �ְ� �����Ѵ�.  
		
			}		
		}
		
		if(b!=NULL)
		{
			for(;b!=NULL;b=b->link){							//b(���)���ٰ� b�� link�� �־ ���� ���� ��������ְ� b�� NULL�� �ƴҶ����� �����Ѵ�. 
				sum = b->value;									//sum���� b�� value���� �ִ´�.
				insert_node_last(mlist3,b->row,b->col,sum);		//insert�Լ��� ȣ���ؼ� mlist3���� b��row, col, value���� �ְ� �����Ѵ�.  
			}		
		}
	}
}  

void matrix_print(ListHeader *mlist,int num)				//matrix��� �Լ� matrix��ȣ�� ����ϱ����� ������ ���� num�� �߰��Ͽ���. 
{
	ListNode *p = mlist->head;								//Listnode���� ������ p���ٰ� mlist head�κ��� �ִ´�. 
	printf("matrix %d\n",num);								//�߰��� num�� �̿��ؼ� matrix��ȣ�� �ش�. 
	
	for(;p;p=p->link){										//���� ������ p�� �̿��ؼ� p���� p�� ��ũ�� �ִ´�. 
		printf("%d, (%d,%d)\n",p->value,p->row,p->col);		//ó������ p�� value��, row, col������ ����Ѵ�.	
	}
	puts("");		//enter�������Ѵ�. 

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

