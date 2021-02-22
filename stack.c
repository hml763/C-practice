#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>			//exit �����Ű�� ���̺귯�� 

typedef int element; 
typedef struct StackNode { 
	element item; 
	struct StackNode *link; 
} StackNode;

typedef struct { 
	StackNode *top; 
	} LinkedStackType;
	
//�ʱ�ȭ�Լ� 
void init(LinkedStackType *s) { 		//s�� top������ NULL�� �ʱ�ȭ��. 
	s->top = NULL; }
	
// ������� �����Լ� 
int is_empty(LinkedStackType *s) { 
	return (s->top == NULL); }			// LinkedStackType����ü�� NULL�� �� ����ȴ�. 
//���� �Լ�
void push(LinkedStackType *s, element item) { 
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode)); 		//�����޸� �Ҵ� 
	if (temp==NULL) { 									//temp�� NULL�϶� ���� 
	fprintf(stderr,"�޸� �Ҵ翡��\n"); 		//����Ǵ�  ��¹� 
	return; } 
	
	else{ temp->item = item;			//NULL�� �ƴҶ� �����. temp�� item�������� �Ű������� ����. 
		  temp->link = s->top; 			//temp�� link�����Ϳ��ٴ� s�� top�����͸� �־���. 
		  s->top = temp; } 				//s�� top�����Ϳ� �޾Ƶ��̴� ��, temp�� �־���. 
}
		  
//�����Լ� 
element pop(LinkedStackType *s) { 		 
	if( is_empty(s) ) { 	//empty �Լ����� �ؼ� �´ٸ�  �Ʒ��� ���๮�� ����Ѵ�. 
		fprintf(stderr,"������ �������\n"); 
		//exit(1); 
		} 
		
	else{ 
		StackNode *temp=s->top; 		//StackNode�� temp�� �����ϰ� s�� top�����͸� �ִ´�. 
		element item = temp->item; 		//������ item���� temp���� item���� �ִ´�. 
		s->top = s->top->link; 			//s�� top�����Ϳ��� s��toplink�� �־��ش�. ���� �����Ͱ��̴�. 
		free(temp); 					//�����޸� �Ҵ��� ���� �������ش�. 
		return item; 
		} 
	}

void display(LinkedStackType *s) {
	LinkedStackType *tmp = (LinkedStackType*)malloc(sizeof(LinkedStackType));		//LinkedStackType�� tmp�� �����޸𸮸� �Ҵ�޾� �������ش�. 
	tmp->top = s->top;															//tmp�� top�����Ϳ� �Ű����� s�� top�� �־��ش�. 	
	
	if(is_empty(s)){
		fprintf(stderr, "������ ��� ����\n");				//������ ����� �� ��µǴ� ���̴�. 
		exit(1);
	}

	else{							
		while(s->top != NULL){			//s�� top�����Ͱ� NULL�� �ƴҶ� �����Ѵ�.  
			printf("%d\n",s->top->item);	//top�� ����Ű�� item�� ����Ѵ�. 
			s->top = s->top->link;			//���� �����͸� ����Ű������  s�� top���� link�� �־��ش�. 
		}
		s->top = tmp->top;			//s�� top�� ���� ������ ���������� ���������Ƿ� �ٽ� tmp�� top�� s�� �־��ش�.  
		free(tmp);					//tmp�� �޸𸮸� �������ش�. 
	}
	puts("");
}

//���ÿ� ����Ǿ� �ִ� ��ҵ��� ������ ��ȯ 
int get_height(LinkedStackType *s) {	
	int num=0;
	LinkedStackType *tmp = (LinkedStackType*)malloc(sizeof(LinkedStackType));		//���ο� �����޸��Ҵ� 
	tmp->top = s->top;				//tmp�� top�����Ϳ� �Ű����� s�� top�� �־��ش�.  
	
	if(is_empty(s))					//������ ����� �� ��µǴ� ���̴�. 
	{
		fprintf(stderr, "������ ��� ����\n");
		exit(1);
	}
	
	else{
		while(s->top != NULL){			//s�� top�����Ͱ� NULL�϶� ���� 
			num++;						//����� ������ num�� ���� 
			s->top = s->top->link;		//s�� top���� s�� top link���� �־��ش�. 
		}
	
		s->top = tmp->top;				//s�� top�� ���� ������ ���������� ���������Ƿ� �ٽ� tmp�� top�� s�� �־��ش�.  
		free(tmp);						//�޸𸮸� �Ҵ����� tmp�� �����Ѵ�. 
	}
	
	return num;			//����� num�� ��ȯ 
}

//s�� ����Ű�� ���ð� t�� ����Ű�� ���ÿ� ���� �����͵��� �Ȱ��� �׿� �ִ��� Ȯ���� �� ������ 1�� ��ȯ�ϰ� ���� ������ 0�� ��ȯ 
int compare(LinkedStackType *s, LinkedStackType *t) {
	LinkedStackType *stack_s = (LinkedStackType*)malloc(sizeof(LinkedStackType));			//���� stack_s, stack_t��� �̸����� �����޸��Ҵ�  
	LinkedStackType *stack_t = (LinkedStackType*)malloc(sizeof(LinkedStackType));
	int num=0;
	stack_s->top = s->top;		//�Ҵ��� �޸��� top���� s�� top�� �־��� 
	stack_t->top = t->top;
	
	if(is_empty(s) || is_empty(t))		//�����ϳ��� ����ٸ� exit�Լ� ����.  
	{
		fprintf(stderr, "������ ��� ����\n");
		exit(1);
	}	
	
	else
	{
		while(s->top != NULL)		//�ؿ� if�Լ� ������ ������ s ���� �ϳ��� ���� �ƴ϶�� �־���. 
		{
			if(get_height(s) != get_height(t))		//�� ������ ���̰� �ٸ��ٸ� �ٷ� 0��ȯ.  
				return 0;
			
			if(s->top->item == t->top->item)		//�ΰ� ������ item���� ������ ���� 
			{
				num++;						//num�� 1�� ����. 
				s->top = s->top->link;		//���� ��ũ�� �Ѿ�Բ� ���ִ� ��ɾ�. 
				t->top = t->top->link;	
			}
			
			else
			{
				return 0;				//if���� �ƴҽ� 0��ȯ 
			}
		
		}
	}
	
	s->top = stack_s->top;				//�޾Ѵ� s���ÿ� �ٽ� �Ҵ��ߴ� �޸��� top�� ���� �־���. �ؿ��� ��������.  
	t->top = stack_t->top;			
	free(stack_s);					//�Ҵ��ߴ� �޸� ����. 
	free(stack_t);
		
	if(num > 0)			//������ �����ߴ� num�� 0���� ũ�� 1��ȯ. 
		return 1;
	
	else
		return 0;		//�ƴҽ� 0��ȯ. 	
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
