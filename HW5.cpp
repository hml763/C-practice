#include <iostream>
#include <String>

using namespace std;

class LoopAdder{
	protected: 
		double num1, num2;
		
	public:
		void print(){
		cout << "ó�� ������ �� ��° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
		cin >> num1;
		cin >> num2;
		}
		
};

class ForLoopAdder : public LoopAdder{
	double sum=0;
	double tmp;
	public:
		double calculate(){
			tmp = num1;
			for(tmp;tmp<=num2;tmp++){
				sum = sum + tmp;
			}
		}
		
		ForLoopAdder(string fl){
			cout << fl << ":" << endl;
		}
		
		
		void run(){
			print(); 
			calculate();
			cout << num1 << "���� " << num2 << "������ �� : " << sum << "�Դϴ�" << endl;
		} 
		
};

int main(){
	ForLoopAdder forLoop("For Loop");     
	forLoop.run();	
}
