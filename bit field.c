#include <Stdio.h>

struct time{
	unsigned int hour : 5;
	unsigned int min : 6;
	unsigned int sec : 6;
};
//각각의 변수의 크기를 정해주고(bit 단위) 다합치면 17bit 이므로 구조체크기는 4byte. 2^4 = 16.  

int main()
{
	struct time t1;
	printf("size of struct time : %d\n\n",sizeof(struct time));
	
	t1.hour = 5;
	t1.min = 30;
	t1.sec= 70;
	
	printf("%02d:%02d:%02d\n",t1.hour,t1.min,t1.sec);
	
	return 0;
}
