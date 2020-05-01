//Code of Troy

//EOF = End Of File = Ctrl + z

#include <Stdio.h>

int main(){
	int number;
	printf("EOF = Ctrl + z\n");
	
	scanf("%d",number);
	
	while(scanf("%d",&number)!=EOF){
		printf("%d\n",number);		
	}
}
