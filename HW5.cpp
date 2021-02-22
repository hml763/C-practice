#include <iostream>
#include <String>

using namespace std;

class LoopAdder{
	protected: 
		double num1, num2;
		
	public:
		void print(){
		cout << "처음 수에서 두 번째 수까지 더합니다. 두 수를 입력하세요 >> ";
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
			cout << num1 << "에서 " << num2 << "까지의 합 : " << sum << "입니다" << endl;
		} 
		
};

int main(){
	ForLoopAdder forLoop("For Loop");     
	forLoop.run();	
}
