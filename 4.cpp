#include <stdio.h>

int main(){
	
	int cola=0, fries=0, hamb=0, set=0, sum=0;
	int h_price = 4000, f_price = 2000, c_price = 1500, set_price = 6500;
	printf("[�ܹ��� : 4000��, ��Ƣ : 2000��, �ݶ� 1500��, ��Ʈ 6500��]\n\n�ܹ��� ����? ");
	scanf("%d",&hamb);
	printf("����Ƣ�� ����? ");
	scanf("%d",&fries);
	printf("�ݶ� ����? ");
	scanf("%d",&cola);
	
	if(hamb < fries){
		if(hamb < cola) 
			set = hamb;
		
		else if(hamb > cola)
			set = cola;

		else
			set = hamb;
	}
	
	else if(hamb < cola){
		if(hamb < fries){
			set = hamb;
		}
		
		else if(hamb > fries){
			set = fries;
		}
		
		else{
			set = hamb;
		}
	}
	
	else if(fries < cola){
		if(fries < hamb){
			set = fries;
		}
		
		else if(fries > hamb){
			set = hamb;
		}
		
		else{
			set = fries;
		}
	}
	
	else if(cola < hamb){
		if(cola < fries){
			set = cola;
		}
		
		else if(cola > fries){
			set = fries;
		}
		
		else{
			set = cola;
		}
	}
	
	else if(hamb == fries && fries == cola){
		set = hamb;
	}
	
	printf("\n\n��ǰ��\t\t�ܰ�\t����\t�ݾ�\n");
	
	if(set > 0){
		printf("��Ʈ\t\t%d\t%d\t%d\n",set_price,set,set_price*set);
		sum = sum + (set_price*set);	
	}
	
	if((hamb-set) > 0){
		printf("�ܹ���\t\t%d\t%d\t%d\n",h_price,hamb-set,(hamb-set)*h_price);
		sum = sum + (hamb-set)*h_price;
	}
	
	if((fries-set) > 0){
		printf("����Ƣ��\t%d\t%d\t%d\n",f_price,fries-set,(fries-set)*f_price);
		sum = sum + (fries-set)*f_price;
	}
	
	if((cola-set) > 0){
		printf("�ݶ�\t\t%d\t%d\t%d\n",c_price,cola-set,(cola-set)*c_price);
		sum = sum + (cola-set)*c_price;	
	}
		
	printf("------------------------------------\n�հ�\t\t\t\t%d\n",sum);
	//printf("min : %d\n",min);
	return 0;
}
